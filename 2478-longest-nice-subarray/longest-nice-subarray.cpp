class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int mx = 0 , i  = 0 , j = 0 ,mask = 0;   
         while(j < nums.size()){
           
            while (i < nums.size() && (mask & nums[j]) != 0) {
                mask ^= nums[i]; 
                i++;
            }
            mask |= nums[j];
            mx = max(mx,j- i + 1);
            j++;
        }

        return mx;
    }
};