class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int>st(nums.begin(),nums.end());
        for(int &num:nums){
            int target = original;
            if(st.find(target) == st.end()){
                return target;
            }
            else{
                original = original*2;
            }
        }
    return original;
    }
};