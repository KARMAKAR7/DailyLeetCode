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
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int>ans;
        vector<int>pow;
        pre(n,pow);
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            long long prod = 1;
            for (int i = l; i <= r; i++) {
                prod = (prod * pow[i]) % MOD;
            }
            ans.push_back((int)prod);
        }
        return ans;
    }
};