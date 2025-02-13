class Solution {
public:
    #define ll long long 
    int minOperations(vector<int>& nums, int k) {
        priority_queue<ll , vector<ll> , greater<ll>>pq(nums.begin(),nums.end());
        int operations = 0;
        while(!pq.empty() && pq.top() < k){
          ll ele_one = pq.top();
          pq.pop();
          ll ele_sec = pq.top();
          pq.pop();
          ll new_ele =  min(ele_one, ele_sec) * 2 + max(ele_one, ele_sec);
          pq.push(new_ele);
          operations++;
        }
        return operations;
    }
};