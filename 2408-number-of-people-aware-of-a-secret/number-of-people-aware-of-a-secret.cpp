class Solution {
public:
    #define ll long long  
    const int MOD = 1e9+7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        ll numbers = 0;
        // we all know that 1 st person know the secret at first day
        vector<int>dp(n+1,0);
        dp[1] = 1; // first person at first day;
        for(int i = 2 ; i <= n ; i++){
            // cheack how many people are eligible for shareing the scret at i th day
            if(i - delay > 0){
                numbers = (numbers + dp[i-delay]) % MOD;
            }
            //cheack how many people are forget at this i th day
            if(i - forget > 0){
                numbers = (numbers - dp[i-forget] + MOD) % MOD;
            }
            dp[i] = (int)numbers;
        }
        ll ans = 0;
        for(int i = n - forget + 1 ; i <= n ; i++){
             if(i > 0){
                ans = (ans + dp[i])%MOD;
             }
        }

        // for(int x:dp) cout << x << " ";
       return (int)ans%MOD;
    }
};