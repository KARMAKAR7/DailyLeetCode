class Solution {
public:
    const int MOD = 1e9 + 7;
    int n;
    int dp[41][1<<10];
    vector<int>Hats[41];
    int solve(int hat , int mask){
        if(mask == (1<<n)-1) return 1;
        if(hat > 40) return 0;

        if(dp[hat][mask] != -1) return dp[hat][mask];

        // skip 
        int ways = solve(hat+1 , mask) % MOD;

        for(int person : Hats[hat]){
            if(!(mask & (1 << person))){
                ways = (ways+ solve(hat+1 , mask|(1 << person)))%MOD;
            }
        }
        return dp[hat][mask] = ways;
    }
    int numberWays(vector<vector<int>>& hats) {
        memset(dp,-1,sizeof(dp));
        n = hats.size();
        for(int i = 0 ; i < n ; i++){
              for(int hat:hats[i]){
                 Hats[hat].push_back(i);
              }
        }
        return solve(1,0);
    }
};