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
        // may be array can have ones so no oprtaions needed for the,
        int ones = 0;
        for (int x : nums) if (x == 1) ++ones;
        if (ones > 0) return nums.size() - ones;

        int ans = nums.size()+1;
        for(int i = 0 ; i < nums.size() ; i++){
               int gc = 0;
               for(int j = i ; j < nums.size() ; j++){
                      gc = gcd(gc,nums[j]);
                      if(gc == 1){  // we found gcd == 1
                          ans = min(ans,j-i);
                      }
               }
        }
        return ans + (nums.size()-1); // we also need covert other elements
    }
};