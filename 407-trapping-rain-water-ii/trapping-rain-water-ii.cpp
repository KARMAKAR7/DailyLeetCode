class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
       if (heightMap.empty() || heightMap[0].empty()) return 0;

        int rows = heightMap.size();
        int cols = heightMap[0].size();
        int totalWater = 0;

        // Min-heap to store {height, row, col}
        priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap;

        // Visited array to mark cells we've already processed
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        // Step 1: Add all boundary cells to the min-heap
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                    minHeap.push({heightMap[i][j], i, j});
                    visited[i][j] = true;
                }
            }
        }

        // Directions for moving to neighbors: right, left, down, up
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        // Step 2: Process the heap
        while (!minHeap.empty()) {
            auto current = minHeap.top();
            minHeap.pop();

            int height = current[0];
            int row = current[1];
            int col = current[2];

            // Check all four neighbors
            for (auto& dir : directions) {
                int nr = row + dir[0];
                int nc = col + dir[1];

                // Check if the neighbor is within bounds and unvisited
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && !visited[nr][nc]) {
                    // Calculate trapped water
                    totalWater += max(0, height - heightMap[nr][nc]);

                    // Update the height of the neighbor to maintain boundary integrity
                    minHeap.push({max(height, heightMap[nr][nc]), nr, nc});

                    // Mark the neighbor as visited
                    visited[nr][nc] = true;
                }
            }
        }

        return totalWater; 
    }
};