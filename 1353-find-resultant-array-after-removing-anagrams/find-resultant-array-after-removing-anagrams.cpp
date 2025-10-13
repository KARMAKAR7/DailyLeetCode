#define fio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
class Solution {
public:
   bool ana(string s1 , string s2){
       if(s1.size() != s2.size()) return false;
       sort(s1.begin(),s1.end());
       sort(s2.begin(),s2.end());
       return s1 == s2;
   }
    vector<string> removeAnagrams(vector<string>& words) {
        fio;
        int n = words.size();
        vector<string>ans;
        for(int i = 0; i < n; i++){
             if(!ans.empty() && ana(ans.back(),words[i])){
                //  ans.push_back(words[i]);
                continue;
             }else{
                ans.push_back(words[i]);
             }
        }
    return ans;
    }
};