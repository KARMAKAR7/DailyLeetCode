class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>suff(n);
        suff[n-1] = nums.back();
        for(int i = n-2 ; i >= 0 ; i--){
            suff[i] = min(suff[i+1],nums[i]);
        }
        int maxi = 0;
        for(int i = 0 ; i < n ; i++){
             maxi = max(maxi,nums[i]);
             if(maxi - suff[i] <= k){
                return i;
             }
        }
        return -1;
    }
};