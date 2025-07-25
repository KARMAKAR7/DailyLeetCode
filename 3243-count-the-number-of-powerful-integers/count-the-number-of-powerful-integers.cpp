class Solution {
public:
    #define ll long long
    ll dp[16][2];
    ll fun(int index,bool tight , int &maxAllowed,string &suffix , string &s){
        if(index == s.size()){
            return 1;
        }
       if(dp[index][tight] != -1){
            return dp[index][tight];
       }
    ll ans = 0;
    int limit = tight ? s[index]-'0' : 9;
    limit = min(limit,maxAllowed);

    int suffixIndex = s.size() - suffix.size();

    if(index >= suffixIndex){
        if(tight == false){
            return dp[index][tight] = 1;
        }

        if(s[index] < suffix[index-suffixIndex]){
            return dp[index][tight] = 0;
        }
        if(s[index] == suffix[index-suffixIndex]){
            return dp[index][tight] = fun(index+1,true,maxAllowed , suffix , s);
        }
        if(s[index] > suffix[index-suffixIndex]){
            return dp[index][tight] = 1;
        }
    }
    for(int d = 0 ; d <= limit ; d++){
        int newTight = tight & (d == s[index]-'0');
        ans += fun(index+1,newTight,maxAllowed,suffix,s);
    }
    return dp[index][tight] = ans;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        ll count1 = 0;
        string l = to_string(start - 1);
        if(l.size() >= s.size()){
            memset(dp,-1,sizeof(dp));
            count1 = fun(0,true,limit,s,l);
        }

        string h = to_string(finish);
        memset(dp,-1LL,sizeof(dp));
        ll count2 = fun(0,true,limit,s,h);
        return count2 - count1;
    }
};