class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sum = 0 , currentFunValue = 0;
        for(int i = 0 ; i < n ; i++){
             sum += nums[i];
             currentFunValue += i * nums[i];
        }

        int ans = currentFunValue;
        for(int k = 1 ; k < n ; k++){
             currentFunValue = currentFunValue + sum - n*nums[n-k];
             ans = max(ans , currentFunValue);
        }
        return ans;
    }
};