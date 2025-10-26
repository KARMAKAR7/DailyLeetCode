class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        long long ans = 0;
        int n = nums1.size();
        int exOp = 0;
        int m = INT_MAX;

        for(int i = 0;i < n;i++) {
            ans += abs(nums1[i]-nums2[i]); 
            int mx = max(nums1[i], nums2[i]);
            int mn = min(nums1[i], nums2[i]);
            if(mx >= nums2[n] and mn <= nums2[n]) {
                exOp = 1;
            } else {
                m = min({abs(nums2[n]-nums1[i])+1,abs(nums2[n]-nums2[i])+1, m});
            }
        }

        if(exOp == 0) ans += m;
        else ans += 1;
        return ans;
    }
};