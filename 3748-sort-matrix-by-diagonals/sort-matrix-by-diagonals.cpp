class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // Sort bottom-left triangle including middle diagonal (descending)
        for (int i = 0; i < n; i++) {
            sortDiagonal(grid, i, 0, false);
        }
        
        // Sort top-right triangle (ascending)
        for (int j = 1; j < n; j++) {
            sortDiagonal(grid, 0, j, true);
        }
        
        return grid;
    }
    
private:
    void sortDiagonal(vector<vector<int>>& grid, int row, int col, bool ascending) {
        int n = grid.size();
        vector<int> diagonal;
        int r = row, c = col;
        
        // Extract diagonal elements
        while (r < n && c < n) {
            diagonal.push_back(grid[r][c]);
            r++;
            c++;
        }
        
        // Sort diagonal
        if (ascending) {
            sort(diagonal.begin(), diagonal.end());
        } else {
            sort(diagonal.rbegin(), diagonal.rend());  // Sort in descending order
        }
        
        // Put sorted values back in the matrix
        r = row, c = col;
        for (int val : diagonal) {
            grid[r][c] = val;
            r++;
            c++;
        }
    }
};
