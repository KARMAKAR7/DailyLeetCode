class Solution {
public:
    using ll = long long;
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        ll ans=0ll;

        if(n < 3) return 0;
        vector<ll>pre(n,-1),suff(n,-1);
        pre[0] = nums[0];
        suff[n-1] = nums[n-1];
        for(int i = 1; i < n ; i++){
            pre[i] = max(pre[i-1],(ll)nums[i]);
        }
        for(int i = n-2; i >= 0 ; i--){
            suff[i] = max(suff[i+1],(ll)nums[i]);
        } 
        

        for(int i = 1 ; i < n-1 ; i++){
            ll diff = (pre[i-1]  - nums[i]);
            if (diff > 0) { 
                ll prod = diff * suff[i+1]; 
                ans = max(ans, prod);
            }
        }
        return ans;
    }
};