class Solution {
public:
    using ll = long long;
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());
        ll res = 0;
        int left = 0;
        ll count = 0;
        for(int right = 0 ; right < n ; right++){
                if(nums[right] == maxi) count++;
                 while(count >= k){
                     if(nums[left] == maxi) count--;
                     left++;
                     res += n - right;
                 }
        }
      return res;
    }
};