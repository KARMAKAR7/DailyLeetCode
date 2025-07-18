class Solution {
public:
#define ll long long 
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size()/3;
        vector<ll>pre(nums.size(),-1); 
        vector<ll>suf(nums.size(),-1);

        ll sum = 0; // minimu n element sum
         priority_queue<ll>pq; // max heap;
         for(int i = 0 ; i< nums.size();i++){
             sum+= nums[i];
             pq.push(nums[i]);


             // pop max ele
             if(pq.size() > n ){
                 sum -= pq.top(); 
                 pq.pop();
             }
             if(pq.size()==n) pre[i] = sum ;

         }

         sum = 0 ;
         priority_queue<ll ,vector<ll> , greater<ll>>pq2; // max heap;
         for(int i =nums.size()-1;i>=0;i--){
             sum+= nums[i];
             pq2.push(nums[i]);


             // pop max ele
             if(pq2.size() > n ){
                 sum -= pq2.top();
                  pq2.pop();
             }
             if(pq2.size()==n) suf[i] = sum ;

         }
          
        ll ans = LONG_LONG_MAX;
        for(int i = n-1 ; i<2*n;i++){
            ans = min(ans ,pre[i]-suf[i+1]);
        }
      return ans;
    }
};