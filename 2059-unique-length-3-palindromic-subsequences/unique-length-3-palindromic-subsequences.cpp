class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<pair<int,int>>vec(26,{-1,-1});
         for(int i = 0 ; i < s.size();i++){
            char ch = s[i];
            int ind = ch -'a';
            if(vec[ind].first == -1){
                vec[ind].first = i;
            }
            vec[ind].second = i;
        }

        int res = 0;
        for(int i = 0 ; i < 26 ; i++){
            if(vec[i] == make_pair(-1,-1)) continue;
            unordered_set<char>st;
            for(int j = vec[i].first+1 ; j <=vec[i].second - 1 ; j++){
                st.insert(s[j]);
            }
            res += st.size();
        }
        return res;
    }
};