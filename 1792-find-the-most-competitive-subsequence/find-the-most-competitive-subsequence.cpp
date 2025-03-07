class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        stack<int>stack;

        for(int i = 0 ; i < n ; i++){

            while(!stack.empty() && nums[i] < stack.top()&&(stack.size()+(n-i) > k)){
                stack.pop();
            }
            
            if(stack.size() < k){
                stack.push(nums[i]);
            }
        }
        vector<int>ans(k);
        for(int i = k-1 ; i>= 0 ; i--){
            ans[i] = stack.top();
            stack.pop();
        }
        return ans;
    }
};