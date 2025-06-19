class Solution {
public:
    const int mod = 1e9+7;
    int dp[2001][51][51];
    int solve(vector<int>&nums , int ind , int prev_1 , int prev_2){
        if(ind == nums.size()) return 1;
        if(dp[ind][prev_1][prev_2] != -1) return dp[ind][prev_1][prev_2];
        int total_counts = 0;

        for(int next_1 = prev_1 ; next_1 <=nums[ind] ; next_1++){
            int next_2 = (nums[ind] - next_1);
            if(next_2 <= prev_2){
                 total_counts = (total_counts + solve(nums , ind+1 ,next_1,next_2))%mod;
            }
        }
       return dp[ind][prev_1][prev_2] = total_counts;
    }
    int countOfPairs(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,0,50);
    }
};