class Solution {
public:
    bool isValid(string word) {
        if(word.size() < 3) return false;
        bool hasV = false;
        bool hasC = false;

        for(char ch : word){
            if(!isalnum(ch)) return false;

            if(isalpha(ch)){
                char lower = tolower(ch);
                if(lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u'){
                    hasV = true;
                }else hasC = true;
            }
        }
      return hasV && hasC;
    }
};