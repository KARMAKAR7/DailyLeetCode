class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
         int n = (int)energy.size();
        vector<long long> dp(n, 0);
        long long ans = LLONG_MIN;

        for (int i = n - 1; i >= 0; --i) {
            dp[i] = energy[i];
            if (i + k < n) dp[i] += dp[i + k];
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};