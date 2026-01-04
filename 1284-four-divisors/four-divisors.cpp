class Solution {
public:
    int helper(int num){
       int div = 0;
       int sum = 0;
       for(int d = 1 ; d * d <= num ; d++){
             if(num % d == 0){
                 int o = num / d;
                 if(d == o){
                      div++;
                      sum += d;
                 }else{
                      div += 2;
                      sum += d + o;
                 }
             }
            if(div > 4){
                return 0;
            }
       }
       return div == 4 ? sum : 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int res = 0;
        for(auto num:nums){
             res += helper(num);
        }
        return res;
    }
};