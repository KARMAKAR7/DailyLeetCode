class Solution {
public:
    bool found = false;  // To stop recursion after finding a valid string

    void solve(string &res , string temp, unordered_set<string>& mpp, int len){
        if (temp.length() == len) {
            if (mpp.find(temp) == mpp.end()) {
                res = temp;
                found = true;  // ✅ Mark as found
            }
            return;
        }

        if (found) return;  // ✅ Stop unnecessary recursion

        for(int i = 0; i <= 1; i++){
            temp.push_back(i + '0');
            solve(res, temp, mpp, len);
            if (found) return;  // ✅ Stop recursion if result is found
            temp.pop_back();
        }
    }
   string findDifferentBinaryString(vector<string>& nums) {
        int n = nums[0].size();
        unordered_set<string> mpp(nums.begin(), nums.end());
        string res = "";
        solve(res, "", mpp, n);
        return res;
    }
};