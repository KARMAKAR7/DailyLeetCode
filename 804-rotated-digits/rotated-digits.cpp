class Solution {
public:
    string s;
    int dp[5][2][2][2]; // pos , tight , strated , changed
    int dfs(int pos ,bool tight , bool started , bool changed){
        if(pos == s.size()){
            return (started && changed) ? 1 : 0;
        }
        if(dp[pos][tight][started][changed] != -1){
            return dp[pos][tight][started][changed];
        }

        int limit = tight ? (s[pos]-'0') : 9;
        int res = 0;

        for(int d = 0 ; d <= limit ; d++){
            bool new_tight = tight && (d==limit);
            if(!started && d == 0){
              res += dfs(pos+1,new_tight , false ,false);
            }
            else{
                if(d == 3 || d == 4 || d == 7) continue;

                bool new_changed = changed;
                if(d == 2 || d == 5 || d == 6 || d == 9){
                    new_changed = true;
                }
                res += dfs(pos+1 , new_tight , true,new_changed);
            }
        }
        return dp[pos][tight][started][changed] = res;
    }
    int rotatedDigits(int n) {
        s = to_string(n);
        memset(dp,-1,sizeof(dp));
        return dfs(0,true,false,false);
    }
};