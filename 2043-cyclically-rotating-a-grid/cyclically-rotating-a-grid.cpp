class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        if(k == 0) return grid;
        int layers = min(n,m) / 2;

        for(int l = 0 ; l < layers ; l++){
            vector<int>nums;
            int top = l ;
            int btm = n - l - 1;
            int left = l;
            int right = m - l - 1;

            // top 
            for(int  i = left ; i <= right ; i++){
                 nums.push_back(grid[top][i]);
            }
            // right

            for(int i = top + 1 ; i <= btm - 1 ; i++){
                 nums.push_back(grid[i][right]);
            }
            //buttom
            for(int i = right ; i >= left ; i--){
                nums.push_back(grid[btm][i]);
            }
            // left
            for(int i = btm - 1 ; i >= top+1; i--){
                nums.push_back(grid[i][left]);
            }

            // rotation of k
            int len = nums.size();

            int rot = k % len;

            rotate(nums.begin() , nums.begin()+rot , nums.end());

            int ind = 0; 

            for(int i = left ; i <= right ; i++){
                 grid[top][i] = nums[ind++];
            }

            for(int i = top + 1 ; i <= btm - 1 ; i++){
                grid[i][right] = nums[ind++];
            }

            for(int i = right ; i >= left ; i--){
                grid[btm][i] = nums[ind++];
            }
            
            for(int i = btm - 1 ; i >= top+1; i--){
                grid[i][left] = nums[ind++];
            }
        }
        return grid;
    }
};