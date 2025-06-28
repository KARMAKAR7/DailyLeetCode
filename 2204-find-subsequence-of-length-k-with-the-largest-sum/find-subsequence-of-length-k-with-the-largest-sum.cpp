class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int,int>>ind;
        for(int i = 0 ; i < n ; i++){
            ind.push_back({nums[i],i});
        }
        sort(ind.begin(),ind.end() , [](auto &a , auto &b){
            return a.first > b.first;
        });

        vector<pair<int,int>>top(ind.begin() , ind.begin()+k);

        sort(top.begin(),top.end() , [](auto &a , auto &b){
         return a.second < b.second;
        });
        vector<int>ans;
        for(auto [val ,ind] : top){
            ans.push_back(val);
        }
        return ans;
    }
};