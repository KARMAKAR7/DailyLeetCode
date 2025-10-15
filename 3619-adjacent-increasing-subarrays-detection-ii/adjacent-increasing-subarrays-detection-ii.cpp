class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int curr = 1;
        int prev = 0;
        int maxi = 0;

        for(int i = 1 ; i < n ; i++){
              if(nums[i] > nums[i-1]){
                curr++;
              }else{
                  prev = curr;
                  curr = 1;
              }
            maxi = max(maxi,curr/2);
            maxi = max(maxi,min(prev,curr));
        }
        return maxi;
    }
};