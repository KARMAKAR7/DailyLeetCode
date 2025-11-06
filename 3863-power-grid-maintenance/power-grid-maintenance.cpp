class Solution {
public:
   void dfs(int node ,  vector<vector<int>> &adj,vector<int>&comp,int _id,unordered_map<int,set<int>>&sameComponents){
           comp[node] = _id;
           sameComponents[_id].insert(node);
           for(auto ng : adj[node]){
               if(comp[ng] == -1){
                    dfs(ng,adj,comp,_id,sameComponents);
               }
           }
   }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<vector<int>> adj(c + 1); // c number of stations are there

        for(auto edge:connections){
             adj[edge[0]].push_back(edge[1]);
             adj[edge[1]].push_back(edge[0]);
        }
        
        int _id = 0;
        vector<int>comp(c+1,-1);
        unordered_map<int,set<int>>sameComponents;
        for(int i = 1 ; i <= c ; i++){
               if(comp[i] == -1){
                   _id += 1;
                   dfs(i,adj,comp,_id,sameComponents);  // mark all the same _id components
               }
        }
        // for(int i = 1 ; i <= c ; i++){
        //        sameComponents[comp[i]].insert(i); 
        // }
        vector<int>result;
        // now we can answer the quires
        for(auto it:queries){
             int ty = it[0];
             int node = it[1];
             if(ty == 1){
                    int id = comp[node];
                   if(sameComponents[id].find(node) != sameComponents[id].end()){
                         result.push_back(node);
                   }else{  // this ndoe is offline we need to find lowest componets in this id
                       int id = comp[node];
                       if(sameComponents[id].empty()){
                          result.push_back(-1);
                       }else{
                           result.push_back(*sameComponents[id].begin());
                       }
                   }
             }else{
                  int id = comp[node];
                  sameComponents[id].erase(node);
             }
        }
        return result;
    }
};