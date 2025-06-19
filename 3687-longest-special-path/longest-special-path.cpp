class Solution {
public:
    int longest_path = 0 ;
    int minCount = INT_MAX;
    int n;
    vector<vector<pair<int, int>>> adj; 
    vector<int>trace;
    void dfs(int node , int par , int s , int e , int pathSum , vector<int>&path , vector<int>&nums){
        int prev = trace[nums[node]];
        trace[nums[node]] = e;

        while(s <= prev){
             pathSum -= path[s];
             s++;
        }
        if(pathSum > longest_path){
             longest_path = pathSum;
             minCount = e - s + 1;
        }else if(pathSum == longest_path){
              minCount = min(minCount  , e - s + 1);
        }

        for(auto &it: adj[node]){
             if(it.first != par){
                 path.push_back(it.second);
                 dfs(it.first , node , s , e+1 , pathSum+ it.second ,path , nums);
                 path.pop_back();
             }
        }
        trace[nums[node]] = prev;
    }
    vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {
        n = edges.size()+1;
        adj.resize(n);
        trace.resize(50001, -1);
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int ln = e[2];
            adj[u].push_back({v,ln});
            adj[v].push_back({u,ln});
        }

        vector<int>path;
        dfs(0,-1,0,0,0,path,nums);
        return {longest_path , minCount};
    }
};