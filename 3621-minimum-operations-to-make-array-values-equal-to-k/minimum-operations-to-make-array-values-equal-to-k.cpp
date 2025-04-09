class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
       set<int>st(nums.begin(),nums.end());
       int miN = *min_element(nums.begin(),nums.end());
       if(miN < k) return -1;

       if(miN == k) return st.size()-1;
       return st.size();
    }
};