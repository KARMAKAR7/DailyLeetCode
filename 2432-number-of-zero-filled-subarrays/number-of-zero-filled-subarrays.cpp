class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long result = 0;
        int n = nums.size();
        long long countZeros = 0;

        for(int i= 0 ; i < n ; i++){
            if(nums[i]==0){
                countZeros++;
            }else{
                countZeros = 0;
            }
            result += countZeros;
        }
      
      return result;
    }
};