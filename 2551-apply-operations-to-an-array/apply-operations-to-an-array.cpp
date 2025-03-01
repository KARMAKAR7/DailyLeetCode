class Solution {
public:
    void op(vector<int>&nums){
        for(int i = 0 ; i < nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                nums[i] = 2*nums[i];
                nums[i+1] = 0;
            }
        }
    }
    vector<int> applyOperations(vector<int>& nums) {
        op(nums);
        int index = 0 ; 
        for(int i = 0 ; i < nums.size();i++){
            if(nums[i]){
                swap(nums[i],nums[index]);
                index++;
            }
        }
      return nums;
    }
};