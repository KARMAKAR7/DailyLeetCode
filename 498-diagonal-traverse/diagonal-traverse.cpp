class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        map<int,vector<int>>cord;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                cord[i+j].push_back(mat[i][j]);
            }
        }
        vector<int>ans;

        bool flip = true;
        for(auto &it:cord){

            if(flip){
                reverse(it.second.begin(),it.second.end());
            }
            for(auto &i:it.second){
                ans.push_back(i);
            }
            flip = !flip;
        }
        return ans;
    }
};