class Solution {
public:
    // int solve(int ind ,int n , vector<int>&costs){ 
    //     if(ind > n) return INT_MAX;
    //     if(ind == n){
    //        return 0;
    //     }
    //     long long op1 = INT_MAX , op2 = INT_MAX , op3 = INT_MAX;
    //     if(ind + 1 <=n) op1 = (costs[ind] + 1) + solve(ind+1 , n , costs);
    //     if(ind+ 2 <=n){
    //        int c = costs[ind+1] + 4 ;
    //        op2 = c + solve(ind+ 2 , n , costs);
    //     }
    //     if(ind +  3 <=n){
    //         int c = costs[ind+ 2] + 9;
    //         op3 = c + solve(ind+ 3 , n , costs);
    //     }
    //     return min({op1,op2,op3});
    // }
    int climbStairs(int n, vector<int>& costs) {
        // return solve(0,n,costs);
         vector<int> dp(n + 1, 0);
        dp[0] = 0;

        for (int j = 1; j <= n; j++) {
            dp[j] = INT_MAX;

            if (j - 1 >= 0) dp[j] = min(dp[j], dp[j - 1] + costs[j - 1] + 1);
            if (j - 2 >= 0) dp[j] = min(dp[j], dp[j - 2] + costs[j - 1] + 4);
            if (j - 3 >= 0) dp[j] = min(dp[j], dp[j - 3] + costs[j - 1] + 9);
        }

        return dp[n];
    }
};