class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.find(part) != string::npos){
            size_t pos = s.find(part);
            s.erase(pos,part.length());
        }
        return s;
    }
};