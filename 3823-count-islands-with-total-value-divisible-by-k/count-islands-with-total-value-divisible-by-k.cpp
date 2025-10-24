class DSU{
    vector<int> size,parent;
    public:
        DSU(int n) {
            size.resize(n+1,1);
            parent.resize(n+1);
            for(int i = 0 ; i <= n; i++) {
                parent[i] = i;
            }
        }
        int findPar(int x) {
            if(parent[x] == x) return parent[x];
            else return parent[x] = findPar(parent[x]);
        }

        void unionFn(int x, int y) {
            int ux = findPar(x);
            int uy = findPar(y);
            if(ux == uy) return;
            if(size[ux] > size[uy]) {
                size[ux] += size[uy];
                parent[uy] = ux; 
            }
            else {
                size[uy] += size[ux];
                parent[ux] = uy; 
            }
        }
        
};
class Solution {
public:
    int getCellVal(int &m, int &n, int &i, int &j){
        return (n * i) + j;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int cells = n*m;
        DSU ds(cells);

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!grid[i][j]) continue;
                int curr = getCellVal(m,n,i,j);
                vector<vector<int>> directions = {{-1,0}, {0,1}, {1,0}, {0,-1}};
                for(auto &dir: directions) {
                    int ni = i + dir[0];
                    int nj = j + dir[1];

                    if(ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] != 0) {
                        int adj = getCellVal(m,n,ni,nj);
                        ds.unionFn(curr,adj);
                    }
                }
            }
        }
        vector<long long> copy(m*n,0);
        for(int i=0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] != 0) {
                    int par = ds.findPar(getCellVal(m,n,i,j));
                    copy[par] += grid[i][j];
                }
            }
        }
        int ans =0;
        for(auto x: copy) {
            if(x != 0 && x % k == 0){
                ans++;
            }
        }
        return ans;
    }
};