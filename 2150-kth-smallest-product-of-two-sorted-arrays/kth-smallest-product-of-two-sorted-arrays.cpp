class Solution {
public:
    long long solve(vector<int>&nums1,vector<int>&nums2 , long long p){
        long long count = 0;
        for(int i = 0 ; i < nums1.size() ; i++){
               if(nums1[i] >= 0){
                  long long l = 0;
                  long long r = nums2.size() - 1;
                  int m = -1;
                  while(l<=r){
                      long long mid = l + (r-l) / 2;
                      long long prd = 1LL * nums1[i] * nums2[mid];
                      if(prd <= p){
                        m = mid;
                        l = mid + 1;
                      }else{
                         r = mid - 1;
                      }
                  }
                count += (m+1);
               }else{
                  long long l = 0;
                  long long r = nums2.size() - 1;
                  int m =  nums2.size();
                  while(l<=r){
                      long long mid = l + (r-l) / 2;
                      long long prd = 1LL * nums1[i] * nums2[mid];
                      if(prd <= p){
                        m = mid;
                        r = mid - 1;
                      }else{
                        l= mid + 1;
                      }
                  }
                count += (nums2.size()-m);
               }
        }
      return count;
    }
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long res = 0;
        long long l = -1e10;
        long long r = 1e10;

        while(l <= r){
            long long mid = l + (r-l) / 2;
            
            long long count = solve(nums1,nums2,mid);
            if(count >= k){
                res = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
      return res;
    }
};