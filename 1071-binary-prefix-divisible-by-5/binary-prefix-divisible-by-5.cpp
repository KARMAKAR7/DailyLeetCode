class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans(nums.size());
        int cur = 0; 

        for (int i = 0; i < nums.size(); i++) {
            cur = ((cur << 1) + nums[i]) % 5;  
            ans[i] = (cur == 0);
        }
        return ans;
    }
};