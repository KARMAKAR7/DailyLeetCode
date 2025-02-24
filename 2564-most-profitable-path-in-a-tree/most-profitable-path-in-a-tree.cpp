class Solution {
public:
    unordered_map<int,vector<int>>adj;
    vector<int>bobPath;
    bool dfs(int node,int par,int bob){
        if(node==bob){
            bobPath.push_back(node);
            return true;
        }
        for(int ngr : adj[node]){
            if(ngr == par) continue;
            if(dfs(ngr,node,bob)){
                 bobPath.push_back(node);
                 return true;
            }
        }
        return false;
    }
    int solve(int node , int par , int dep , vector<int>&amount, unordered_map<int,int>&time){
        int profit = 0;

        if(time.count(node)){
            if(time[node] > dep){
                profit += amount[node];
            }
            else if(time[node] == dep){
                profit += amount[node]/2;
            }
        }else{
            profit+= amount[node];
        }
        int maxi = INT_MIN;
        bool isLeaf = true;
        for(auto ngr :adj[node]){
            if(ngr != par){
            isLeaf = false;
            maxi = max(maxi , solve(ngr , node ,dep+1,amount , time));
        }
    }
        

       return isLeaf ? profit : profit+maxi;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
       for(auto &edge : edges){
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
       }

       // find boob path 
       dfs(bob,-1,0);
       reverse(bobPath.begin(),bobPath.end());
       unordered_map<int,int>time;
       for(int i = 0 ; i < bobPath.size() ; i++){
            time[bobPath[i]] = i;
       }
       int res = solve(0,-1,0,amount ,time);
       return res;
    }
};