class Solution {
public:
void dfs(int node, vector<vector<int>>& graph, unordered_set<int>& visited, vector<int>& component) {
    visited.insert(node);
    component.push_back(node);
    for (const auto& neighbor : graph[node]) {
        if (visited.find(neighbor) == visited.end()) {
            dfs(neighbor, graph, visited, component);
        }
    }
 }

 bool isComplete(const vector<int>& component, const vector<vector<int>>& graph) {
    int n = component.size();
    for (int i = 0; i < n; i++) {
        if (graph[component[i]].size() != n - 1) {
            return false;
        }
    }
    return true;
 }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
            for (const auto& edge : edges) {
                graph[edge[0]].push_back(edge[1]);
                graph[edge[1]].push_back(edge[0]);
            }

            unordered_set<int> visited;
            int count = 0;
            for (int i = 0; i < n; i++) {
                if (visited.find(i) == visited.end()) {
                    vector<int> component;
                    dfs(i, graph, visited, component);
                    if (isComplete(component, graph)) {
                        count++;
                    }
                }
            }
       return count;
    }
};