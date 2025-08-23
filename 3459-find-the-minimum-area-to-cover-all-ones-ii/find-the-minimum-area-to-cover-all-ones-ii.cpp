class Solution {
public:
    //Clockwise Rotation
    vector<vector<int>> rotateMatrix(vector<vector<int>>& grid){
        int m = grid.size();       
        int n = grid[0].size();   

        vector<vector<int>> rotated(n, vector<int>(m));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rotated[j][m - i - 1] = grid[i][j];
            }
        }

        return rotated;
    }

    int minimumArea(int rowStart, int rowEnd, int colStart, int colEnd, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int minCol = n;
        int maxCol = -1;
        int minRow = m;
        int maxRow = -1;

        for(int i = rowStart; i < rowEnd; i++) {
            for(int j = colStart; j < colEnd; j++) {
                if(grid[i][j] == 1) {
                    minCol = min(minCol, j);
                    maxCol = max(maxCol, j);
                    minRow = min(minRow, i);
                    maxRow = max(maxRow, i);
                }
            }
        }

        return (maxCol - minCol + 1) * (maxRow - minRow + 1);
    }

    int solve(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int result = INT_MAX;

        // Row Splits
        for(int rowSplit = 1; rowSplit < m; rowSplit++){
            // Column splits
            for(int colSplit = 1; colSplit < n; colSplit++){
                int top      = minimumArea(0, rowSplit, 0, n, grid);
                int bottomLeft  = minimumArea(rowSplit, m, 0, colSplit, grid);
                int bottomRight = minimumArea(rowSplit, m, colSplit, n, grid);
                
                result = min(result, top + bottomLeft + bottomRight);
            }
        }

        // Row Splits
        for(int rowSplit = 1; rowSplit < m; rowSplit++) {
            // Column splits
            for(int colSplit = 1; colSplit < n; colSplit++) {

                int topLeft   = minimumArea(0, rowSplit, 0, colSplit, grid);
                int topRight  = minimumArea(0, rowSplit, colSplit, n, grid);
                int bottom    = minimumArea(rowSplit, m, 0, n, grid);

                result = min(result, topLeft + topRight + bottom);
            }
        }

        for(int firstSplit = 1; firstSplit < m - 1; firstSplit++){
            for(int secondSplit = firstSplit + 1; secondSplit < m; secondSplit++){
                int top    = minimumArea(0, firstSplit, 0, n, grid);
                int middle = minimumArea(firstSplit, secondSplit, 0, n, grid);
                int bottom = minimumArea(secondSplit, m, 0, n, grid);

                result = min(result, top + middle + bottom);
            }
        }
        
        return result;
    }

    int minimumSum(vector<vector<int>>& grid) {

        int result = solve(grid);

        vector<vector<int>> rotatedGrid = rotateMatrix(grid);

        result = min(result, solve(rotatedGrid));

        return result;
    }
};
