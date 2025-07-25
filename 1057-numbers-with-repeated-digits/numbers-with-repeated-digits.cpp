class Solution {
public:
    // use bitmask to track the used for tarcking
    int dp[10][2][2][1024];
    int fun(int index , bool tight , bool repeat , int bitmask , string &s){
        if(index == s.size()){
            if(repeat && bitmask){
                return 1;
            }
          return 0;
        }

        if(dp[index][tight][repeat][bitmask] != -1){
            return dp[index][tight][repeat][bitmask];
        }

        int ans = 0;
        int limit = tight ? s[index]-'0' : 9;

        for(int d = 0 ; d <= limit ; d++){
            int newTight = tight & (d==limit);
            if((bitmask == 0) && (d == 0)){
                 ans += fun(index+1 , false,repeat , bitmask , s);
            }
            else if(bitmask & (1 << d)){
                ans += fun(index+1,newTight , true , bitmask ,s);
            }else{
                ans += fun(index+1 , newTight , repeat , bitmask |(1 << d),s);
            }
        }
        return dp[index][tight][repeat][bitmask] = ans;
    }
    int numDupDigitsAtMostN(int n) {
        string s = to_string(n);
        memset(dp,-1,sizeof(dp));
        return fun(0,true,false,0,s);
    }
};