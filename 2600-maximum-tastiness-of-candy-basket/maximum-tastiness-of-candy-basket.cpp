class Solution {
public:
    bool is(int min_dif , vector<int>&price , int k){
        int last = price[0];
        int count = 1;
        for(int i = 1 ; i < price.size();i++){
             if(price[i] - last >= min_dif){
               last = price[i];
               count++;
             }
        }
      return count >=k;
    }
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(),price.end());


        int l = 0 , h = price.back() - price.front();

        int ans  = 0;
        while(l <= h){
            int mid = l +(h - l) /2;

            if(is(mid,price,k)){
                ans = mid;
                l = mid+1;
            }else{
                h = mid-1;
            }
        }
      return ans;
    }
};