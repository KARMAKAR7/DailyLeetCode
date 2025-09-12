class Solution {
public:
    bool doesAliceWin(string s) {
        int volewsCoount = 0;
        auto is = [](char ch){
          char c = tolower(ch);
          return (c=='a') || (ch=='e') || (ch == 'i') || (ch == 'o') || (ch=='u');
        };
        for(auto ch : s){
             if(is(ch)){
                volewsCoount++;
             }
        }
        while(volewsCoount >=2){
            volewsCoount = volewsCoount/2;
        }
       return volewsCoount == 1;
    }
};