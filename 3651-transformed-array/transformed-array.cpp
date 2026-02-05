class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>res(n);
        for(int i = 0 ; i < nums.size();i++){
             if(nums[i] == 0){
                  res[i] = nums[i];
             }
             else{
                  int n_ind = (i+nums[i] % n + n) % n;
                  res[i] = nums[n_ind];
             }
        }
        return res;
    }
};