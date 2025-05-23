class Solution {
public:
     int helper(vector<int>& nums, int level, int currentXOR) {
        // base condition
        if (level == nums.size()) return currentXOR;
        // creating include 
        int include = helper(nums, level + 1, currentXOR ^ nums[level]);
        // creating exclude
        int exclude = helper(nums, level + 1, currentXOR);
        
        return include + exclude;
    }
    int subsetXORSum(vector<int>& nums) {
         return helper(nums, 0, 0);
    }
};