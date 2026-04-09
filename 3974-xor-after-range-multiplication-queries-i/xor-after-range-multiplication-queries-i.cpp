class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int mod = 1e9 + 7;
        
        for(auto q : queries){
            int l = q[0] , r = q[1] , k = q[2] , v = q[3];

            for(int i  = l ; i <= r ; i += k){
                nums[i] = (1ll * nums[i] * v) % mod;
            }
        }
        long long res = 0;
        for(auto i : nums){
             res ^= i;
        }
        return res;
    }
};