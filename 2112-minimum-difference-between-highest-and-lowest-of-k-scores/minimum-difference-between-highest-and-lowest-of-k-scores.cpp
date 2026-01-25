class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0 , r = 0;
        int ans = INT_MAX;
        sort(nums.begin(),nums.end());
        while(r < n){
              if(r-l+1 > k){
                  l++;
              }
              if(r - l + 1 == k) ans = min(ans,(nums[r]-nums[l]));
              r++;
        }
        return ans;
    }
};