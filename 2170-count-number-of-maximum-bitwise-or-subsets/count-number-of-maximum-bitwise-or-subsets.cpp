class Solution {
public:
    int helper(vector<int>&nums , int idx ,int currOr, const int maxi){
        if(idx == nums.size()){
          return currOr == maxi ? 1 : 0 ;
        }
     
     int inc = helper(nums,idx+1,currOr|nums[idx],maxi);
     int exc = helper(nums,idx+1,currOr,maxi);
        
    return inc + exc;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxi = 0;
        for(auto it:nums){
            maxi = maxi | it;
        }
      return helper(nums,0,0,maxi);
    }
};