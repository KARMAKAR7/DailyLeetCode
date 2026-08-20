class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        ans[0] = nums[0];
        ans[n-1] = nums[1];

        int idx = 0 , revIdx = n - 1;

        for(int i = 2 ; i < n ; i++){
            if(ans[idx] > ans[revIdx]){
                ans[++idx] = nums[i]; 
            }else{
                ans[--revIdx] = nums[i];
            }
        }
        reverse(ans.begin() + revIdx , ans.end());
     return ans;
    }
};