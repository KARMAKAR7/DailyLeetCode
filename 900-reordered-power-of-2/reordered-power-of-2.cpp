class Solution {
public:
    bool reorderedPowerOf2(int n) {
        auto sortDigits = [](int x){
            string s = to_string(x);
            sort(s.begin(),s.end());
            return s;
        };
        unordered_set<string>p;
        for(int i = 1 ; i <= 1e9 ; i = i << 1){
              p.insert(sortDigits(i));
        }
        return p.count(sortDigits(n));
    }
};