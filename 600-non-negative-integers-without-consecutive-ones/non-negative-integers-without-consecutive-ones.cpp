class Solution {
public:
    int dp[32][2][2];
    int fun(int index , bool tight , bool prev , int &n){
        if(index == 32){
            return 1;
        }
        if(dp[index][tight][prev] != -1){
            return dp[index][tight][prev];
        }

        int ans = 0;

        int limit = tight ? (n >>(31-index)) & 1 : 1;

        for(int d = 0 ; d <= limit ; d++){
            int newTight = tight & (d==limit);
            if((d & prev) == 0){
                ans += fun(index+1 , newTight , d , n);
            }
        }

        return dp[index][tight][prev] = ans;
    }
    int findIntegers(int n) {
        memset(dp,-1,sizeof(dp));

        return fun(0,true,false,n);
    }
};