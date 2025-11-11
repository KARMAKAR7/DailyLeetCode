class Solution {
public:
    // int solve(vector<string>&strs , int ind , int m ,int n,vector<vector<vector<int>>>&dp){
    //     if(ind == strs.size()) return 0;
    //     if( dp[ind][m][n] != -1) return  dp[ind][m][n];
    //     int ones = 0 , zeros = 0;
    //     for(char ch : strs[ind]){
    //           if(ch == '1') ones++;
    //           else zeros++;
    //     }
    //     int take = 0;
    //     if(ones <= n && zeros <= m){
    //         take = 1 + solve(strs,ind+1,m-zeros,n-ones,dp);
    //     }
    //     int notTake = solve(strs,ind+1 , m ,n,dp);
    //     return dp[ind][m][n] = max(take ,notTake);
    // }
    int findMaxForm(vector<string>& strs, int m, int n) {
    //    vector<vector<vector<int>>>dp(strs.size(),vector<vector<int>>(m+1,vector<int>(n+1,-1)));
    //    return solve(strs,0,m,n,dp);
          vector<vector<int>>dp(m+1 , vector<int>(n+1 , 0));
            
            for(auto str : strs){
                 int z = 0 , o = 0;
                 for(int i = 0 ; i < str.size();i++){
                     if(str[i] == '1') o++;
                     else z++;
                 }
                 for(int i = m ; i >= z ; i--){
                     for(int j = n ; j >= o ; j--){
                         dp[i][j] = max(dp[i][j],dp[i-z][j-o]+1);
                     }
                 }
            }
        return dp[m][n];
    }
};