class Solution {
public:
    int N;
    int val = 0;
    void fill(vector<vector<int>>&grid,int r_start , int r_end , int c_start,int c_end){
         int size = r_end - r_start;
         if(size == 1){
            grid[r_start][c_start] = val++;
            return;
         }

        int mid_r = (r_start + r_end) / 2;  // to find the midddle of the row
        int mid_c = (c_start + c_end) / 2;  // to find the midddle of the col

         fill(grid,r_start,mid_r,mid_c,c_end); // top right;
         fill(grid,mid_r,r_end,mid_c,c_end); //  bottom-right 
         fill(grid,mid_r,r_end,c_start,mid_c); //  bottom-left 
         fill(grid,r_start,mid_r,c_start,mid_c);  //  top-left
    }
    vector<vector<int>> specialGrid(int n) {
      N = 1 << n;
      vector<vector<int>>grid(N,vector<int>(N));
      fill(grid,0,N,0,N); 
      return grid; 
    }
};