class Solution {
public:
    bool canPartition(vector<int>& nums) {
    int n = nums.size();
    int sum = accumulate(nums.begin(),nums.end(),0);

        if(sum % 2 == 1){
            return false;
        }
        int target = sum /2 ;

        vector<vector<bool>>dp(n+1,vector<bool>(target+1,false));

        for(int i = 0 ; i <= n ; i++){
            dp[i][0] = true;
        }
        
        for(int i = n-1 ; i >= 0 ; i--){
            for(int j = 0 ; j <= target ; j++){
                bool take = false;
                if(j - nums[i] >= 0){
                   take =  dp[i+1][j-nums[i]];
                }
                bool nottake = dp[i+1][j];
                dp[i][j] = take || nottake;
            }
        }
        return dp[0][target];
    }
};