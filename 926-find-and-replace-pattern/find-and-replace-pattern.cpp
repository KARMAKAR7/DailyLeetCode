class Solution {
public:
     bool isIsomorphic(string s, string t) {
        char map_s[128] = { 0 };
        char map_t[128] = { 0 };
        int len = s.size();
        for (int i = 0; i < len; ++i)
          {
            if (map_s[s[i]]!=map_t[t[i]]) return false;
            map_s[s[i]] = i+1;
            map_t[t[i]] = i+1;
          }
        return true; 
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        for(auto i : words){
            if(isIsomorphic(i,pattern)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};