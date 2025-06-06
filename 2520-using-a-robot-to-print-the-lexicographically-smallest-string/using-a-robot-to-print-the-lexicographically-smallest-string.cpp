class Solution {
public:
    string robotWithString(string s) {
        int n = s.length();
        
        vector<char> minToRight(n);
        minToRight[n - 1] = s[n - 1];
        for (int i = n - 2; i >= 0; i--) 
            minToRight[i] = min(minToRight[i + 1], s[i]);
        
        string t = "";
        string paper = "";
        int i = 0;
        
        while (i < n) {
            t.push_back(s[i]);
            
            char minChar = (i+1 < n) ? minToRight[i+1] : s[i];
            while (!t.empty() && t.back() <= minChar) {
                paper += t.back();
                t.pop_back();
            }

            i++;
        }

        //Remaining
        while(!t.empty()) {
            paper.push_back(t.back());
            t.pop_back();
        }
        
        return paper;
    }
};