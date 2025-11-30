class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int totalSum = 0;
        for(auto num:nums){
             totalSum = (totalSum + num)%p;
        }
        if(totalSum == 0) return 0;

        int target = totalSum;
        unordered_map<int,int>pre;
        pre[0] = -1;
        
        int currSum = 0;
        int miniLen = nums.size();

        for(int i = 0 ; i < nums.size() ; i++){
              currSum = (currSum + nums[i]) % p;
              int req = (currSum - target + p) % p;

              if(pre.find(req) != pre.end()){
                   miniLen = min(miniLen , i - pre[req]);
              }

              pre[currSum] = i;
        }
       return miniLen == nums.size() ? -1 : miniLen;
    }
};