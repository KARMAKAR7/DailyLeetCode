class Solution {
public:
    const int mod = 1e9+7;
    int numberOfWays(int n, int x) {
        // Step 1: precompute powers
        vector<int> powers;
        for (int i = 1; ; i++) {
            long long p = pow(i, x);
            if (p > n) break;
            powers.push_back((int)p);
        }

        // Step 2: bottom-up DP
        vector<long long> dp(n + 1, 0);
        dp[0] = 1; // one way to make sum 0 (choose nothing)

        for (int p : powers) {
            for (int sum = n; sum >= p; sum--) {
                dp[sum] =  (dp[sum] + dp[sum - p])%mod;
            }
        }

        return dp[n];
    }
};
