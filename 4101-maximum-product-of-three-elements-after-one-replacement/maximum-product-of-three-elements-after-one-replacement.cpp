class Solution {
public:
    using ll =  long long;
    ll m = 100000;
    long long maxProduct(vector<int>& nums) {
       ll l_1 = 0;
       ll l_2 = 0;
       for(auto i : nums){
          ll num = llabs(i);
           if(num >= l_1){
               l_2 = l_1;
               l_1 = num;
           }
           else if(num > l_2){
               l_2 = num;
           }
       }
       return l_1 * l_2 * m;
    }
};