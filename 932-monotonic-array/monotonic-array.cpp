class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool isone = true , istwo = true;
        int prev = nums[0];
        for(int i = 1 ; i < nums.size();i++){
            if(prev > nums[i]){
               isone = false;
               break;
            }
            else{
                prev = nums[i];
            }
        }
        prev = nums[nums.size()-1];
        for(int i = nums.size()-2 ; i >= 0;i--){
            if(prev > nums[i]){
               istwo = false;
               break;
            }else{
                prev = nums[i];   
            }
        }
      return isone | istwo;
    }
};