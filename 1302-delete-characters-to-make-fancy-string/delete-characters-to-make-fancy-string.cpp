class Solution {
public:
    string makeFancyString(string s) {
      string result = "";
      for(char ch : s){
        if(result.size() >= 2 && result[result.size()-1] ==ch &&  result[result.size()-2] ==ch){
            continue;
        }
        result += ch;
      }
      return result;
    }
};