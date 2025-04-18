class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
         int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        vector<int> rowMax(n, 0), colMax(m, 0);

        // Priority queue: max-heap (value, i, j)
        priority_queue<tuple<int, int, int>> pq;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                pq.emplace(mat[i][j], i, j);

        // To store all same-value cells for a batch update
        while (!pq.empty()) {
            int currVal = get<0>(pq.top());
            vector<tuple<int, int, int>> sameValCells;

            // Group cells with same value
            while (!pq.empty() && get<0>(pq.top()) == currVal) {
                sameValCells.push_back(pq.top());
                pq.pop();
            }

            // First pass: compute dp without updating row/col max yet
            for (auto& [val, i, j] : sameValCells) {
                dp[i][j] = max(rowMax[i], colMax[j]) + 1;
            }

            // Second pass: update row/col max
            for (auto& [val, i, j] : sameValCells) {
                rowMax[i] = max(rowMax[i], dp[i][j]);
                colMax[j] = max(colMax[j], dp[i][j]);
            }
        }

        // Find the answer
        int ans = 0;
        for (auto& row : dp)
            for (int v : row)
                ans = max(ans, v);
        return ans;
    }
};