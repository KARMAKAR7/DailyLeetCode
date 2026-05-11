class Solution {
public:
    int maxFixedPoints(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>>arr;

        for(int i = 0 ; i < n ; i++){
             int num  = nums[i];
             int diff = i - nums[i];

             if(diff >= 0 && num >= 0){
                  arr.push_back({diff,num});
             }
        }
        sort(arr.begin(),arr.end());
        vector<int>ans;
        for(auto it:arr){
            int val = it.second;

            auto nxt = lower_bound(ans.begin(),ans.end(),val);

            if(nxt == ans.end()){
                 ans.push_back(val);
            }else{
                *nxt = val;
            }
        }
        return ans.size();
    }
};