class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
       unordered_set<char> st(brokenLetters.begin(), brokenLetters.end());

        auto hasBroken = [&](const string &s) {
            for (auto ch : s) {
                if (st.find(ch) != st.end()) {
                    return true; 
                }
            }
            return false;
        };

        string temp = "";
        int cnt = 0;
        for (int i = 0; i < text.length(); i++) {
            if (text[i] != ' ') { 
                temp += text[i];
            } else {
                if (!hasBroken(temp)) cnt++;
                temp = "";
            }
        }
        if (!temp.empty() && !hasBroken(temp)) {
            cnt++;
        }

        return cnt;
    }
};