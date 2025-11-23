class Solution {
public:
    unordered_map<string,int>dp;
    int fun(int ind,vector<int>&nums ,int r){
        if(ind == nums.size()){
            return (r==0) ? 0 :INT_MIN;
        }
        string key = to_string(ind) + "#" + to_string(r);
        if(dp.find(key) != dp.end()) return dp[key];
        int newr = (r+ nums[ind])%3;
        int pick = nums[ind] + fun(ind+1,nums,newr);
        int notPick = fun(ind+1,nums,r);
        return dp[key] = max(pick,notPick);
    }
    int maxSumDivThree(vector<int>& nums) {
        dp.clear();
        return fun(0,nums,0);;
    }
};