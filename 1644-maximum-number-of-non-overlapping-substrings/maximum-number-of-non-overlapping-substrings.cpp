class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int>first(26,-1);
        vector<int>last(26,0);
        vector<bool>valid(26,true);
        vector<string>ans;
        // marking first and last index of each charcter

        for(int i = 0 ; i < n ; i++){
            int idx = s[i] - 'a';
            if(first[idx] == -1){
                first[idx] = i;
            }
            last[idx] = max(last[idx],i);
        }
        // now check the conditaions
        for(int ch = 0 ; ch < 26 ; ch++){
             if(first[ch] == -1) continue;

             for(int i = first[ch] ; i <= last[ch] ; i++){
                 if(first[s[i]-'a'] < first[ch]){
                    valid[ch] = false;
                    break;
                 }

                 last[ch] = max(last[ch] , last[s[i] - 'a']);
             }
        }
        int lst = INT_MAX;

        for(int i = n - 1 ; i >= 0 ; i--){
            int ch = s[i] - 'a';

            if(!valid[ch]) continue;

            if(i == first[ch] && last[ch] < lst){
                ans.push_back(s.substr(i,last[ch] - i+1));
                lst = i;
            }
        }
        return ans;
    }
};