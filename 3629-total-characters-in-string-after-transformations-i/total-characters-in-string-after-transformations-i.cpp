class Solution {
public:
    const int MOD = 1e9+7;
    #define ll long long
    int lengthAfterTransformations(string s, int t) {
        vector<ll>charCount(26,0);

        for(auto ch : s){
            charCount[ch -'a']++;
        }

        for(int i = 0 ; i < t ; i++){
            vector<ll>update(26,0);
            for(int ch  = 0 ; ch < 26 ; ch ++){
                if(ch == 25){
                    // update a
                    update[0] = (update[0] + charCount[ch])%MOD;
                    // uadate b
                    update[1] = (update[1] + charCount[ch])%MOD;
                }else{
                    // update next ch
                     update[ch+1] = (update[ch+1] + charCount[ch])%MOD;

                }
            }
            charCount = update;
        }

        ll res = 0;
        for(auto c:charCount){
            res = (res+c)%MOD;
        }
        return res;
    }
};