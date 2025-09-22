class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>f;
        for(int i = 0 ; i < nums.size() ; i++){
            f[nums[i]]++;
        }
        int maxf = INT_MIN;
        for(auto it:f){
             maxf = max(maxf,it.second);
        }
        int ans = 0;
        for(auto it:f){
            if(maxf == it.second) ans += it.second;
        }
        return ans;
    }
};