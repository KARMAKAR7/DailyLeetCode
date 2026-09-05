class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>preMaxi(n);
        preMaxi[0] = nums[0];
        for(int i = 1 ; i < n ; i++){
            preMaxi[i] = max(preMaxi[i-1],nums[i]);
        }

        int ind = -1;
        int mini = nums[n-1];
        for(int i = n - 1 ; i >= 0 ; i--){
              mini = min(mini,nums[i]);
              if(preMaxi[i] - mini <= k){
                ind = i;
              }
        }
        return ind;
    }
};