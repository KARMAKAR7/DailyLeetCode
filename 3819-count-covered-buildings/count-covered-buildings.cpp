class Solution {
public:
    void pre(unordered_map<int,vector<int>>&rowMap,unordered_map<int,vector<int>>&colMap,vector<vector<int>>& buildings){
        for(int i = 0 ; i < buildings.size(); i++){
            int r = buildings[i][0];
            int c = buildings[i][1];
            rowMap[r].push_back(c);
            colMap[c].push_back(r);
        }
    }
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
       unordered_map<int,vector<int>>rowMap;
       unordered_map<int,vector<int>>colMap;
       pre(rowMap,colMap,buildings);
       for (auto &p : rowMap) sort(p.second.begin(), p.second.end());
       for (auto &p : colMap) sort(p.second.begin(), p.second.end());
       
       int ans = 0;
       for(auto &b :buildings){
            int x = b[0];
            int y = b[1];

            auto &row = rowMap[x];
            auto &col = colMap[y];

            auto it = lower_bound(row.begin(),row.end(),y);
            bool left = (it != row.begin());
            bool right = (it+1 != row.end());

            auto it_1 = lower_bound(col.begin(),col.end(),x);
            bool top = (it_1 != col.begin());
            bool btm = (it_1 + 1 != col.end());

            if(left && right && top && btm){
                 ans ++;
            }
       }
     return ans;
    }
};