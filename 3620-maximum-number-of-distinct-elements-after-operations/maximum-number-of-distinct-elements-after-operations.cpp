class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
       sort(nums.begin(),nums.end());

       long long oc = LONG_MIN;
       int ans = 0;

       for(auto it:nums){
          long long left = it-k;
          long long right = it+k;
          if(oc < right){
               long long nw = max(oc+1,left);
               oc = nw;
               ans++;
          }
       }
       return ans;        
    }
};