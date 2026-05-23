class Solution {
public:
    bool check(vector<int>& nums) {
      int n = nums.size();
      int rotationCount = 0;
      for(int i = 0 ; i < n-1 ; i++){
            if(nums[i] > nums[i+1]) {
                rotationCount++;
                if(rotationCount > 1){
                    return false;
                }
            }
        }
        return rotationCount == 1 ? (nums[0] >=nums[n-1]) : true;   
    }
};