class Solution {
public:

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
          int n = equations.size();
        
        unordered_map<string, vector<pair<string, double>>> adj;
        
        for(int i = 0; i<n; i++) {
            
            string u   = equations[i][0];
            string v   = equations[i][1];
            double val = values[i];
            
            adj[u].push_back({v, val});        //To handle a/c
            adj[v].push_back({u, 1.0/val});    //To handle c/a
        }
        
        vector<double> result;
        
        for(auto &query : queries) {
            
            string src = query[0];
            string dst = query[1];
            
            double ans     = -1.0;
            double product = 1.0;
            
            if(adj.find(src) != adj.end()) {
                unordered_set<string> vis;
                queue<pair<string,double>>q;
                q.push({src,product});
                vis.insert(src);
                while(!q.empty()){
                    auto p = q.front();
                    q.pop();
                    if(p.first == dst){
                        ans = p.second;
                        break;
                    }
                    for(auto &node:adj[p.first]){
                        string u = node.first;
                        double val = node.second;
                        if(vis.find(u) == vis.end()){
                             double nw = val*p.second;
                             q.push({u,nw});
                             vis.insert(u);
                        }
                    }
                } 
            }
            result.push_back(ans);
         }
        
        return result;
    }
};