class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        int maxDist = -1;
        queue<pair<int,int>>q;

        for(int i = 0 ; i < n  ; i++){
             for(int j = 0 ; j < m ; j++){
                 if(grid[i][j] == 1){
                     q.push({i,j});
                 }
             }
        }

        if(q.empty() || q.size() == n*m) return -1; // no land or no water

        vector<pair<int, int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()){
            int s = q.size();
            maxDist++;
            for(int i = 0 ; i < s ; i++){
                  auto [x,y] = q.front();
                  q.pop();
                 for(auto [dx, dy]:dir){
                     int nx = x + dx , ny = y + dy;
                       if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 0){
                            grid[nx][ny] = 1 ; // mark as a land 
                            q.push({nx,ny});
                       }
                 }
            }
        }
      return maxDist;
    }
};