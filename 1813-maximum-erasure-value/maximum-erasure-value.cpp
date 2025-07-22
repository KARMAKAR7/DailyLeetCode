class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
         int n = nums.size();
         unordered_set<int>st;
         int start = 0 , end = 0;
         int ans = 0,sum = 0;
         while(end < n){
             while(st.find(nums[end]) != st.end()){
                  st.erase(nums[start]);
                  sum -= nums[start];
                  start++;
             }
            st.insert(nums[end]);
            sum+= nums[end];

            ans = max(ans,sum);
            end++;
         } 
         return ans;
    }
};