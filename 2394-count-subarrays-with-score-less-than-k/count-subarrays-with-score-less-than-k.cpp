class Solution {
public:
    using ll = long long;
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        // vector<ll>pre(n,0);
        // pre[0] = nums[0];
        // for(int i = 1 ; i < n ; i++){
        //       pre[i] = pre[i-1] + nums[i];
        // }
        ll count = 0;
        ll sum = 0;
        ll left = 0;
        for(int right = 0 ; right < n ; right++){
                sum += nums[right];

                while(sum*(right-left+1) >=k){
                     sum -= nums[left];
                     left++;
                }

            count += (right - left+1);
        }
        return count;
    }
};