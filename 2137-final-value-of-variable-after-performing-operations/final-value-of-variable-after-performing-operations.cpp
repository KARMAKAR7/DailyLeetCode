class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        unordered_map<string, int> mpp{
            {"++X", 1},
            {"X++", 1},
            {"--X", -1},
            {"X--", -1}
        };
        int ans = 0;
        for(auto i : operations){
              ans += mpp[i];
        }
        return ans;
    }

};