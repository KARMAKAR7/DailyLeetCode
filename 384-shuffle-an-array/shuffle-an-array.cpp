class Solution {
      vector<int> nums;
public:
    Solution(vector<int>& nums) {
        this->nums = nums;
    }
    
    vector<int> reset() {
        return nums;
    }
    
    vector<int> shuffle() {
        vector<int> result(nums);
        for (int i = result.size() - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            swap(result[i], result[j]);
        }
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */