class Solution {
public:

    int minimumArea(vector<vector<int>>& grid) {
     int n = grid.size() , m = grid[0].size();

     int max_r = INT_MIN , max_c = INT_MIN , min_r = INT_MAX, min_c = INT_MAX;

     for(int i = 0 ; i < n ; i++){
         for(int j = 0 ; j < m ; j++){
              if(grid[i][j]){
                 max_r = max(max_r , i);
                 min_r = min(min_r, i);

                 max_c = max(max_c,j);
                 min_c = min(min_c,j);
              }
         }
     }

     if(max_r == INT_MAX) return 0;

    return (max_r - min_r + 1) * (max_c - min_c + 1);
    }
};