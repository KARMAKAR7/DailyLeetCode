class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size();
        int n = grid[0].size();
        int startVal = grid[0][0];
        
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        dist[0][0] = startVal;
        pq.emplace(startVal, 0, 0);
        
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!pq.empty()) {
            auto [current_max, x, y] = pq.top();
            pq.pop();
            
            if (current_max > dist[x][y]) continue;
            
            for (auto& dir : dirs) {
                int nx = x + dir[0];
                int ny = y + dir[1];
                
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                
                int new_max = max(current_max, grid[nx][ny]);
                if (new_max < dist[nx][ny]) {
                    dist[nx][ny] = new_max;
                    pq.emplace(new_max, nx, ny);
                }
            }
        }
        
        vector<int> distValues;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                distValues.push_back(dist[i][j]);
            }
        }
        sort(distValues.begin(), distValues.end());
        
     
        vector<int> answer;
        for (int q : queries) {
            if (q <= startVal) {
                answer.push_back(0);
            } else {
                auto it = upper_bound(distValues.begin(), distValues.end(), q - 1);
                answer.push_back(it - distValues.begin());
            }
        }
        
        return answer;
    }
};