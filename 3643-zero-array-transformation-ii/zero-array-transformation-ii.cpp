class Solution {
public:
    bool isPossible(int Op , vector<int>nums , vector<vector<int>>&queries){
        int n = nums.size();
        vector<int>diff(n+1,0);
        for(int i = 0 ; i < Op ; i++){
             int left = queries[i][0];
             int right = queries[i][1];
             int val = queries[i][2];

             diff[left] -= val;
             diff[right+1] += val;
        }
        int currentDiff = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            currentDiff += diff[i];
            nums[i] += currentDiff;
            if(nums[i] > 0){
                return false;
            }
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();

        int left = 0  , right = n;
        int ans =  -1;
        while(left <= right){
            int mid = left + (right - left)/2;

            if(isPossible(mid,nums,queries)){
                ans = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return ans ;
    }
};