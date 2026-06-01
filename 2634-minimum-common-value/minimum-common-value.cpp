class Solution {
public:
//  bool search(vector<int>& nums, int target) {
//         int n = nums.size();
//         int l = 0;
//         int h = n - 1;
//         while(l <= h) {
//             int mid = l + (h - l) / 2;
//             if(nums[mid] == target) return true;
//             else if(nums[mid] > target) h = mid - 1;
//             else l = mid + 1;
//         }
//         return false;
//     }
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
    //   int n = nums1.size();
    //     for(int i = 0; i < n; i++) {
    //         if(search(nums2, nums1[i])) return nums1[i];
    //     }
    //     return -1;
    // unordered_map<int, int> mp;
    //     for (int num : nums1) {
    //         mp[num]++;
    //     }
    //     for (int num : nums2) {
    //         if (mp[num] > 0) {
    //             return num;
    //         }
    //     }
    //     return -1;
       unordered_set<int> s(nums1.begin(), nums1.end());
        for (int i = 0; i < nums2.size(); i++) {
            if (s.count(nums2[i]) > 0) {
                return nums2[i];
            }
        }
        return -1;
    }
};