class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
       int n = nums.size();
    //    int maxVal = *max_element(nums.begin(),nums.end());
    //    int bits = maxVal == 0 ? 0 : 1 + log2(maxVal);
       vector<int>nge(32,n);
       vector<int>ans(n,0);

       for(int i = n-1 ; i >= 0 ; i--){
            int ner = i;
            for(int j = 0 ; j < 32; j++){
                if(nums[i] & 1 << j){
                    nge[j] = i;
                }
                else if(nge[j] != n){
                    ner = max(ner , nge[j]);
                }
            }
            ans[i] = ner - i + 1;
       }
       return ans;
    }
};