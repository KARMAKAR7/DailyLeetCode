class Solution {
public:
    int m, n;
    unordered_map<int, vector<vector<int>>> directions = {
        {1, {{0, -1}, {0, 1}}},
        {2, {{-1, 0}, {1, 0}}},
        {3, {{0, -1}, {1, 0}}},
        {4, {{0, 1}, {1, 0}}},
        {5, {{0, -1}, {-1, 0}}},
        {6, {{-1, 0}, {0, 1}}}
    };

    bool dfs(vector<vector<int>>& grid, int row, int col,
             vector<vector<bool>>& visited) {

        if (row == m - 1 && col == n - 1) 
            return true;

        visited[row][col] = true;

        for (auto& dir : directions[grid[row][col]]) {
            int newRow = row + dir[0];
            int newCol = col + dir[1];

            if (newRow < 0 || newRow >= m ||
                newCol < 0 || newCol >= n ||
                visited[newRow][newCol]) 
                    continue;

            for (auto& backDir : directions[grid[newRow][newCol]]) {
                if (newRow + backDir[0] == row &&
                    newCol + backDir[1] == col) {

                    if (dfs(grid, newRow, newCol, visited))
                        return true;
                }
            }
        }

        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        return dfs(grid, 0, 0, visited); 
    }
};