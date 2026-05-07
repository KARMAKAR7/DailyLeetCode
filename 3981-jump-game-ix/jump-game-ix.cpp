class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefixMax(n);
        prefixMax[0] = nums[0];

        for(int i = 1 ; i < n ; i++){
            prefixMax[i] = max(prefixMax[i-1],nums[i]);
        }
        vector<int>suffixMin(n);
        suffixMin[n-1] = nums[n-1];

        for(int i = n - 2 ; i >= 0 ; i--){
            suffixMin[i] = min(suffixMin[i+1],nums[i]);
        }

        vector<int>ans(n);
        ans[n-1] = prefixMax[n-1];
        for(int i = n - 2 ; i >= 0 ; i--){
             if(prefixMax[i] <= suffixMin[i+1]){
                 ans[i] = prefixMax[i];
             }
             else if(prefixMax[i] > suffixMin[i]){
                  ans[i] = ans[i+1];
             }
        }
        return ans;
    }
};