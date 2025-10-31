class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int>seen(n+1,-1);
        vector<int>ans;
        for(int i = 0 ; i < n ; i++){
             if(seen[nums[i]] != -1){
                ans.push_back(nums[i]);
             }
             seen[nums[i]] = 1;
        }
        return ans;
    }
};