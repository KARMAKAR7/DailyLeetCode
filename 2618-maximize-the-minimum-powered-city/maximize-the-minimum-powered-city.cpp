class Solution {
public:
    using ll = long long;
    bool predicate(vector<int>& stations, ll target ,int r,int k){
          int n = stations.size();
          vector<ll> pref(n+1, 0);
          vector<ll> power(n+1, 0);
            for (int i = 0; i < n; ++i) pref[i+1] = pref[i] + stations[i];
            for (int i = 0; i < n; ++i) {
                int L = max(0, i - r);
                int R = min(n - 1, i + r);
                power[i] = pref[R+1] - pref[L];
            }
           vector<ll>diff(n+1,0);
           ll add = 0;
           ll sum = 0;
           for(int i = 0 ; i < n ; i++){
                   sum += diff[i];
                   ll curr = power[i] + sum; // current power of i th city

                   if(curr < target){  // we can place some station here 
                         ll need = target - curr;
                         add += need;  
                         if(add > k){
                            return false; // we add  more than k stations
                         }
                        sum += need;
                        int pos = i + 2*r + 1;   // we try to place at i + r position becuse it can provide the power to i th position also
                                                 // in this question this is the most trickey part that how we think of it
                                                 // i th station can provide power in range [i-r to i + r]
                                                 // so if we install at i + r position a power station 
                                                 // it provides index = i - (i+r) wichich is i;
                                                 // max postion i + r to i + r
                        if(pos <= n) diff[pos] -= need;
                   }
           }
        return true; 
    }
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        ll total = 0;
        for (int x : stations) total += x; // try to chosee lowest number of power plants
        ll start = 0 , end = total + k ,ans = 0;
        // vector<ll>preStation(n+1,0);
        // preStation[0] = stations[0];
        // for(int i = 1 ; i < n ; i++){
        //      preStation[i] = preStation[i-1] + stations[i];
        // }

        while(start <= end){
             ll mid = start + (end - start)/2;
             if(predicate(stations,mid,r,k)){
                 ans = mid;
                 start = mid + 1;
             }else{
                 end = mid - 1;
             }
        }
       return ans;
    }
};