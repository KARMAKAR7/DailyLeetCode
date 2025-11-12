class Solution {
public:
    int minOperations(vector<int>& nums) {
        int g = 0;
        for(int i = 0 ; i < nums.size();i++){
            g = __gcd(nums[i],g);
        }
        if(g != 1){
            return -1; // impossible case
        }
        // may be array can have ones so no oprtaions needed for them,
        int ones = 0;
        for (int x : nums) if (x == 1) ++ones;
        if (ones > 0) return nums.size() - ones;
        /*
           the core thing is wee need to find a subarray that have gcd == 1
           if we find the subarry with gcd == 1
           the we can pass this to adject elements
           so operation will be 
           
           // first we need to convert all the elemnts of in subarray with gcd == 1
           for them reuired operations will be there lenngth
           + the other elemnts that are not in this subarray 
        */
        int ans = nums.size()+1;
        for(int i = 0 ; i < nums.size() ; i++){
               int gc = 0;
               for(int j = i ; j < nums.size() ; j++){
                      gc = __gcd(gc,nums[j]);
                      if(gc == 1){  // we found gcd == 1
                          ans = min(ans,j-i);
                      }
               }
        }
        return ans + (nums.size()-1); // we also need covert other elements
    }
};