class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
      // Step 1: Build the adjacency list for the tree
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int components = 0; // To count the number of valid k-divisible components

        // Step 2: Depth-First Search to calculate subtree sums
        function<long long(int, int)> dfs = [&](int node, int parent) {
            long long subtreeSum = values[node]; // Start with the value of the current node
            for (int neighbor : adj[node]) {
                if (neighbor != parent) { // Avoid revisiting the parent
                    long long childSum = dfs(neighbor, node); // Recursively calculate child sum
                    if (childSum % k == 0) {
                        components++; // A valid component is formed
                    } else {
                        subtreeSum += childSum; // Add the child's sum to the current node's sum
                    }
                }
            }
            return subtreeSum;
        };

        // Step 3: Start DFS from node 0
        long long totalSum = dfs(0, -1);

        // Step 4: Check if the total sum is divisible by k
        if (totalSum % k == 0) {
            components++;
        }

        return components;  
    }
};