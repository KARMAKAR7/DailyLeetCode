class Solution {
public:
    int longestSubarray(vector<int>& nums) {
      int maxi = 0 , len = 0 ,s = 0;

      for(int i = 0 ; i < nums.size();i++){
            if(nums[i] > maxi){
                maxi = nums[i];
                len = 0;
                s = 0;
            }
            if(nums[i]==maxi){
                s++;
            }else{
                 s = 0;
            }
            len = max(len,s);
      } 
      return len; 
    }
};