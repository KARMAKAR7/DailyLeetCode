class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int x : nums) sum += x;
        if (sum % 2 != 0) return 0;
        return n - 1;
    }
};