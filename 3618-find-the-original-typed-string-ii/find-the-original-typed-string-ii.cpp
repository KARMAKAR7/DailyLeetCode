class Solution {
public:
    using ll = long long;
    ll mod = 1e9+7;
    int possibleStringCount(string word, int k) {
        ll n = word.size();
        ll count = 1 , total = 1;
        vector<int>grp;
        for(ll i = 1 ; i < n ; i++){
            if(word[i] == word[i-1]){
                count++;
            }else{
                total = (total * count) % mod;
                grp.push_back(count-1);
                count = 1;
            }
        }
        // add the last grp
        total = (total * count) % mod;
        grp.push_back(count-1);
        
        ll s = grp.size();
        if(k <= grp.size()){
            return total;
        }
        k = k - grp.size();
        vector<ll>dp(k);
        dp[0] = 1;

        for(auto x : grp){
            vector<ll>prefix(k);
            prefix[0] = dp[0];
            for(ll i = 1 ; i < k ; i++){
               prefix[i] = (prefix[i-1] + dp[i])%mod;
            }
            for(ll i = 0 ; i < k ; i++){
                // i could have an another loop for sumation
                // taking 0 , 1 , 2 , ... x elements
                 if(i-x-1 >= 0) dp[i] =( prefix[i] - prefix[i-x-1] + mod) % mod;
                 else dp[i] = prefix[i];
             }
        }
        ll invalidOp = 0;
        for(ll x :dp){
            invalidOp = (invalidOp + x) % mod;
        }
       return (total - invalidOp + mod)%mod;
    }
};