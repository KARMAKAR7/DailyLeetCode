class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ops = 0;
        vector<int>st;

        for(auto num : nums){
             while(!st.empty() && st.back() > num) st.pop_back();

             if(num > 0){
                 if(st.empty() || st.back() < num){
                        st.push_back(num);
                        ++ops;
                 }
             }
        }
       return ops;
    }
};