class Solution {
public:
    #define ll long long
    bool ispossible(ll time , vector<int>&ranks , int cars){
        ll carCount = 0;
        for(int i = 0 ; i < ranks.size() ; i++){
             carCount += sqrt(time/ranks[i]);
        }
        return carCount >= cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        ll n = ranks.size();
        ll left = 1 , right = (ll)*min_element(ranks.begin(),ranks.end()) * (ll)cars * cars;
        ll ans = right;
        while(left <= right){
            ll mid = left + (right - left)/2;
            if(ispossible(mid , ranks , cars)){
               ans = mid;
               right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
      return ans;
    }
};