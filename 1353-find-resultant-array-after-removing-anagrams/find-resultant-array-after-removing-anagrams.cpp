#define fio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
class Solution {
public:
   bool ana(string &s1 , string &s2){
       unordered_map<char,int>f;
       for(auto i:s1){
            f[i]++;
       }
       for(auto i:s2){
           f[i]--;
           if(f[i]==0){
               f.erase(i);
           }
       }
       return f.empty();
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