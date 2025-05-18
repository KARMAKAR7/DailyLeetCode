class Solution {
public:
    const int mod = 1e9+7;
    vector<string>preprocessing;
    vector<vector<int>>dp;
    void pre(string curr , char prev , int len , int r){
        if(len == r){
            preprocessing.push_back(curr);
            return;
        }
        for(char ch:{'R','Y','G'}){
            if(prev == ch){
                continue;
            }
            pre(curr+ch , ch , len+1,r);
        }
    }
     bool valid(string &curr , string &prev,int m){
        for(int j = 0 ; j < m ; j++){
            if(curr[j]==prev[j]){
                return false;
            }
        }
       return true;
    }
     int solve(int rem , int prev,int m){
        if(rem == 0){
            return 1;
        }
        if (dp[rem][prev] != -1) return dp[rem][prev];
        int ways = 0;
        string p = preprocessing[prev];
        for(int  i = 0 ; i < preprocessing.size() ; i++){
             if(i == prev) continue;
             string curr = preprocessing[i];
             if(valid(curr,p,m)){
                ways = (ways + solve(rem-1,i,m))%mod;
             }
        }
      return dp[rem][prev] = ways;
    }
    int numOfWays(int n) {
        pre("",'#',0,3);
        dp = vector<vector<int>>(n+1, vector<int>(preprocessing.size()+1, -1));
        int res = 0;
         for(int i = 0 ; i < preprocessing.size();i++){
            res = (res + solve(n-1,i,3))%mod;
         }
         return res;
    }
};