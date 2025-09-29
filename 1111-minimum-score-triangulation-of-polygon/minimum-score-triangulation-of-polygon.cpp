class Solution {
public:
    int fun(int first ,int last ,vector<int>& values,vector<vector<int>>&dp){
    //   if(last - first <=1) return 0;
      if(first+1 == last) return 0;
      if(dp[first][last]!=-1){
        return dp[first][last];
      }
      int ans = 1 << 30;
      for(int i = first+1 ; i < last ; i++){
          ans = min(ans , fun(first , i , values,dp)+fun(i,last,values,dp)
          +values[first]*values[last]*values[i]);
      }
      return dp[first][last] = ans;
    } 
    int minScoreTriangulation(vector<int>& values) {
        vector<vector<int>>dp(51 ,vector<int>(51,-1));
        return fun(0,values.size()-1,values,dp);
    }
};