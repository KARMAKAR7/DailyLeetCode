class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
       int diff = 0;
        int n = nums.size();

        for(int i=0;i<n;i++){
            int cur_diff;

            if(i == n-1){
                cur_diff = nums[i] - nums[0];
            }
            else{
                cur_diff = nums[i] - nums[i+1];
            }

            diff = max(diff, abs(cur_diff));
        }

        return diff;
    }
};