class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        unordered_set<string>mpp(supplies.begin(),supplies.end());

        unordered_map<string, vector<int>>adj;
        vector<int>indegree(n,0);
        vector<string>res;

        for(int i = 0 ; i < n ; i++){
             for(string ing : ingredients[i]){
                  if(!mpp.count(ing)){
                    adj[ing].push_back(i);
                    indegree[i]++;
                  }
             }
        }

        queue<int>q;
        for(int i = 0 ; i < n ; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            auto i = q.front();
            q.pop();
            res.push_back(recipes[i]);
            
            for(auto ind : adj[recipes[i]]){
                 indegree[ind]--;
                 if(indegree[ind] == 0){
                    q.push(ind);
                 }
            }
        } 
        return res;
    }
};