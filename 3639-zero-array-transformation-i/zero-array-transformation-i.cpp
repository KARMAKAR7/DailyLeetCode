class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int>diff(nums.size()+1,0);
        for(int i = 0 ; i < n ; i++){
            int l = queries[i][0];
            int r = queries[i][1];

            diff[l] += 1;
            diff[r+1] -= 1;
        }
        for(int  i = 1 ; i < diff.size(); i++){
            diff[i] += diff[i-1];
        }
        for(int i = 0 ; i < nums.size();i++){
            if(nums[i]- diff[i] > 0){
                return false;
            }
        }
        return true;
    }
};