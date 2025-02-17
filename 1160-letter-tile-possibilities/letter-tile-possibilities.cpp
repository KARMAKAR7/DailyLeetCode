class Solution {
public:
    int count;
    void solve(string s, string &tiles,unordered_set<string>&sq,vector<bool>&vis){
        sq.insert(s);
        for(int ind = 0 ; ind < tiles.size() ; ind++){
             if(!vis[ind]){
                vis[ind] = true;
                solve(s+tiles[ind],tiles,sq,vis);
                vis[ind] = false; 
             }
        }
    }
    int numTilePossibilities(string tiles){
        unordered_set<string>sq;
        vector<bool>vis(tiles.length(),false);
        solve("",tiles,sq,vis);
        return sq.size()-1;
    }
};