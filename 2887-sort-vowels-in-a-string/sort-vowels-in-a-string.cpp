class Solution {
public:
    bool isVowel(char ch) {
        ch = tolower(ch); 
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    string sortVowels(string s) {
        int n = s.size();
        string t = "";
        vector<char>v;
        for(auto ch :s){
            if(isVowel(ch)){
                v.push_back(ch);
            }
        }
        sort(v.rbegin(),v.rend());
        for(int i = 0 ; i < n ; i++){
              if(!isVowel(s[i])){
                 t += s[i];
              }else{
                  t+= v.back();
                  v.pop_back();
              }
        }
        cout << t << " ";
        return t;
    }
};