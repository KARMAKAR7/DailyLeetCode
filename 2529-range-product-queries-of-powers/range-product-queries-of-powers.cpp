class Solution {
public:
    const int MOD = 1e9 + 7;
    void pre(int n,vector<int>&pow){
         for (int i = 0; i < 31; i++) {
            if (n & (1 << i)) {  // check if the i-th bit is set
                pow.push_back(1 << i);
            }
        }
    }
    long long modPow(long long base, long long exp) {
        long long res = 1;
        while (exp > 0) {
            if (exp & 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int>ans;
        vector<int>pow;
        pre(n,pow);
        int m = pow.size();
        vector<long long> prefix(m);
        prefix[0] = pow[0] % MOD;
        for (int i = 1; i < m; i++) {
            prefix[i] = (prefix[i - 1] * pow[i]) % MOD;
        }
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            long long prod = prefix[r];
            if (l > 0) {
                prod = (prod * modPow(prefix[l - 1], MOD - 2)) % MOD; // modular inverse
            }
            ans.push_back((int)prod);
        }
        return ans;
    }
};