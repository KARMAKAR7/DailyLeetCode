class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>matrix(m,vector<int>(n,0));

        for(auto &it:guards){
              matrix[it[0]][it[1]] = 2;
        }

        for(auto &it:walls){
              matrix[it[0]][it[1]] = 3;
        }

        auto mark = [&](int r , int c)->void{
              // mark up
              for(int i = r - 1 ; i >= 0 ; i--){
                   if(matrix[i][c] == 3 || matrix[i][c] == 2) break;
                   matrix[i][c] = 1;
              }
              // mark down
              for(int i = r+1 ; i < m ; i ++){
                   if(matrix[i][c] == 3 || matrix[i][c] == 2) break;
                   matrix[i][c] = 1;
              }
              // mark left
               for(int i = c-1 ; i >= 0 ; i--){
                   if(matrix[r][i] == 3 || matrix[r][i] == 2) break;
                   matrix[r][i] = 1;
              }
              // mark right
               for(int i = c+1 ; i < n; i ++){
                   if(matrix[r][i] == 3 || matrix[r][i] == 2) break;
                   matrix[r][i] = 1;
              }

        };
         for(auto it:guards){
              mark(it[0],it[1]);
        }
        int ans = 0;
        for(auto r : matrix){
             for(auto c : r){
                   if(c == 0) ans++;
             }
        }
      return ans;
    }
};