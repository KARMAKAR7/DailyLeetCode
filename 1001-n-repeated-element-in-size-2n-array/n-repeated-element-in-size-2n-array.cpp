class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(auto ele:nums){
              mpp[ele]++;
        }
        int n = (nums.size() / 2 );
        // cout << n ;
        int ans = -1;
        for(auto [ele,cnt]:mpp){
            if(cnt == n){
                ans = ele;
                break;
            }
        }
        return ans;
    }
};