class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
           int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(k, 1));
        int result = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                int modulo = (nums[i] + nums[j])%k;
                dp[i][modulo] = max(dp[i][modulo], 1 + dp[j][modulo]);
                result = max(result, dp[i][modulo]);
            }
        }

        return result;
    }
};