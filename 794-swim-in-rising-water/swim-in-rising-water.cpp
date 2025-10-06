class Solution {
public:
    int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    int solve(int t,vector<vector<int>>& grid,int i , int j , int n ,  vector<vector<int>>&vis){
        if(i == n- 1 && j == n-1){
            return true;
        }
        vis[i][j] = true;
        for(auto dir : dirs){
            int new_i = dir[0] + i;
            int new_j = dir[1] + j;
            if(new_i >=0 && new_i< n && new_j >=0 && new_j< n && !vis[new_i][new_j] && grid[i][j] <= t && grid[new_i][new_j] <= t){
                if(solve(t,grid,new_i,new_j,n,vis)){
                    return true;
                }
            } 
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int low = 0 , high = n*n-1;
        while(low < high){
            int mid = low + (high - low)/2;
            vector<vector<int>>vis(n,vector<int>(n,0));
            if(solve(mid,grid,0,0,n,vis)){
                high = mid;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};