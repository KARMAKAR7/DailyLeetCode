class Solution {
public:
    // void f(vector<int>&nums, int curInd , int prevInd , vector<vector<int>>& dp ,vector<int>&ans, vector<int>&temp){
    //      if(curInd>=nums.size()){
    //         if(temp.size()> ans.size()){
    //            ans = temp; 
    //         }
    //         return;
    //      }

    //      //include 
    //      int include = 0;
    //      if(prevInd == -1 || (nums[curInd] % nums[prevInd]==0 ||nums[prevInd] % nums[curInd]==0 )){
    //         temp.push_back(nums[curInd]);
    //         f(nums,curInd+1,curInd,dp,ans,temp);
    //         temp.pop_back();

    //      }
    //      //exclude 
    //       f(nums,curInd+1,prevInd,dp,ans,temp);
    //  }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
         int n = nums.size();
         sort(nums.begin(),nums.end());

         vector<int>dp(n,1);
         vector<int>prev_idx(n,-1);

         int last_index = 0;
         int maxl = 1;

         for(int i = 1; i< n ;i++){
             for(int j = 0 ; j< i ; j++){
                   if(nums[i]%nums[j] == 0){
                       if(dp[i] < dp[j]+1){
                           dp[i] = dp[j]+1;
                           prev_idx[i] = j;
                       }
                       if(dp[i]>maxl){
                           maxl = dp[i];
                           last_index = i;
                       }

                   }
             }
         }
         vector<int>ans;
         while(last_index >=0){
             ans.push_back(nums[last_index]);
             last_index = prev_idx[last_index];
         }
         return ans;

    }
};