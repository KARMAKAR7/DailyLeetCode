class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if(nums.empty()) return 0;

        int maxLen = 1;
        int inLen = 1;
        int decLen = 1;

        for(int i = 1 ; i < nums.size();++i){
            if(nums[i] > nums[i-1]){
                inLen++;
                decLen = 1;
            }
            else if(nums[i] < nums[i-1]){
                decLen++;
                inLen = 1;
            }
            else{
                inLen = 1;
                decLen = 1;
            }
            maxLen = max({maxLen , inLen , decLen});
        }
        return maxLen;
    }
};