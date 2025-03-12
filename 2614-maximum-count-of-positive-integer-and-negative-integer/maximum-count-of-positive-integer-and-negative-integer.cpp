class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int p = 0 , n = 0;
        for(auto num:nums){
            if(num > 0){
               p++;
            }
            else if(num == 0 ){
               continue;
            }else{
                n++;
            }
        }
    return max(p,n);
 }
};