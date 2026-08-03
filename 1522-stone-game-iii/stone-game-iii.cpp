class Solution {
public:
  // recursion 
    //  int fun(vector<int>& s, int i ){
    //    if(i==s.size()) return 0;
    //    int ans = INT_MIN;
    //    int total = 0 ;

    //    for(int x = 1 ; x<=3 ; x++){
    //        if(i+x-1 >=s.size()) break;
    //        total +=s[i+x-1];
    //        ans = max(ans, total - fun(s ,i+x );
    //    }
    //    return ans;
    // }

    //memo
    // int fun(vector<int>& s, int i , vector<int>&dp){
    //    if(i==s.size()) return 0;
    //    if(dp[i]!= -1){
    //        return dp[i];
    //    }
    //    int ans = INT_MIN;
    //    int total = 0 ;

    //    for(int x = 1 ; x<=3 ; x++){
    //        if(i+x-1 >=s.size()) break;
    //        total +=s[i+x-1];
    //        ans = max(ans, total - fun(s ,i+x , dp));
    //    }
    //    return dp[i] = ans;
    // }
      int fun(vector<int>& s){
       vector<int>dp(s.size()+1,0);
       for(int i = s.size()-1;i>=0;i--){
            int ans = INT_MIN;
            int total = 0 ;

            for(int x = 1 ; x<=3 ; x++){
                if(i+x-1 >=s.size()) break;
                total +=s[i+x-1];
                ans = max(ans, total - dp[i+x]);
            }
            dp[i] = ans;
       }
       return dp[0];
    }

    //tabulation
    string stoneGameIII(vector<int>& s) {
        //vector<int>dp(s.size()+1,-1);
        //int ans = fun(s,0);
       // int ans = fun(s,0 ,dp);
        int ans = fun(s);
        if(ans>0) return "Alice";
        if(ans<0) return "Bob";
        return "Tie";
    }
};