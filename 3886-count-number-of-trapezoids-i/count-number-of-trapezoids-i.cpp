class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int,int>mpp;
        int mod = 1e9 + 7 ;
        long long ans = 0 , sum = 0;
        for(auto &p : points){
            mpp[p[1]]++;
        }
        for(auto &[_,pn]:mpp){
            long long edge = (long long)pn * (pn - 1) / 2;
            ans += edge * sum;
            sum += edge;
        }
        return ans % mod;
    }
};