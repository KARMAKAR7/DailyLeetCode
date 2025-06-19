class Solution {
public:
    bool dfs(int curr, int parent, int n, vector<vector<int>>& adj,
             vector<int>& visited) {
        visited[curr] = 1;
        for (auto it : adj[curr]) {
            if (!visited[it]) {
                if (dfs(it, curr, n, adj, visited)) {
                    return true;
                }
            } else if (it != parent) {
                return true;
            }
        }
        return false;
    }
    long long maxScore(int n, vector<vector<int>>& edges) {
        if(n==1){
            return 1;
        }else if(n==2){
            return 1*2;
        }
        vector<vector<int>> adj(n);
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> visited(n, 0);
        bool cycle = dfs(0, -1, n, adj, visited);
        long long ans = 0;

        vector<long long> nums(n);
        for (int i = 0; i < n; i++) {
            nums[i] = i + 1;
        }

        ans += (nums[n - 1] * nums[n - 2]);
        ans += (nums[n - 1] * nums[n - 3]);
        int i = n - 2;
        while (i >= 0 && i - 2 >= 0) {
            ans += (nums[i] * nums[i - 2]);
            i -= 2;
        }
        i = n - 3;
        while (i >= 0 && i - 2 >= 0) {
            ans += (nums[i] * nums[i - 2]);
            i -= 2;
        }
        if(cycle){
            ans+=(nums[0]*nums[1]);
        }
        return ans;
    }
};



