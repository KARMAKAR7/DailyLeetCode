class Solution {
public:
    using ll = long long;

    ll dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& values) {
        // leaf node (except root)
        if (adj[node].size() == 1 && parent != -1) {
            return values[node];
        }

        ll children_sum = 0;
        for (auto child : adj[node]) {
            if (child == parent) continue;
            children_sum += dfs(child, node, adj, values);
        }

        // choose minimum cost
        return min((ll)values[node], children_sum);
    }

    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n = values.size();
        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        ll total = 0;
        for (auto v : values) total += v;

        ll min_keep = dfs(0, -1, adj, values);

        return total - min_keep;
    }
};