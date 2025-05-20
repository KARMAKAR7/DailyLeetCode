class Solution {
public:
    int solve(vector<vector<int>>& queries,int i , int target , int k ,vector<vector<int>>&dp){
        if(target == 0) return k;
        if(k >= queries.size() || target < 0) return queries.size()+1;
        if(dp[target][k] != -1) return dp[target][k];
        
        int res = solve(queries,i,target , k+1 , dp);
        if(queries[k][0] <= i && i<= queries[k][1]){
            res = min(res , solve(queries,i,target-queries[k][2],k+1,dp));
        }
        return dp[target][k] = res;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int ans = -1 ;
        for(int i = 0 ; i < nums.size() ; i++){
            vector<vector<int>>dp(nums[i]+1,vector<int>(queries.size()+1,-1));
            ans = max(ans , solve(queries,i,nums[i],0,dp));
        }
        return (ans > queries.size())?-1:ans;
    }
};