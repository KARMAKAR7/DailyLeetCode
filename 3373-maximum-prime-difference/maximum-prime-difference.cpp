class Solution {
public:
    bool p(int e){
        if(e<=1) return 0;
        for(int i = 2 ; i*i <= e ; i++){
              if(e % i == 0) return 0;
        }
     return 1;
    }
    int maximumPrimeDifference(vector<int>& nums) {
        int n = nums.size();
        int f_id = 0;
        int l_id = 0;

        for(int i = 0 ; i < n ; i++){
            if(p(nums[i])){
                f_id = i;
                break;
            }
        }
         for(int i = n-1 ; i >= 0 ; i--){
            if(p(nums[i])){
                l_id = i;
                break;
            }
        }

        return l_id - f_id;
    }
};