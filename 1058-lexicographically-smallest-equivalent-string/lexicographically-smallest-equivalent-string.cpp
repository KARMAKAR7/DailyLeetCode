class Solution {
public:
    char DFSFindMinChar( unordered_map<char , vector<char>>adj , char node , 
    vector<bool>&vis){
        vis[node-'a'] =1;
        char minChar = node;

        for(char& v :adj[node]){
              if(vis[v-'a']==0){
                  minChar = min(minChar ,DFSFindMinChar(adj , v , vis));
              }
        }
        return minChar;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.length();
        int m = baseStr.length();

        unordered_map<char , vector<char>>adj;

        for(int i = 0 ; i< n ;i++){
              char u = s1[i];
              char v = s2[i];

               adj[u].push_back(v);
               adj[v].push_back(u);
            
        }
        string res;
        for(int i = 0 ; i< m ;i++){
            char ch = baseStr[i];

            vector<bool>vis(26,0);

            char minChar = DFSFindMinChar(adj , ch , vis);
             res.push_back(minChar);

        }
        return res;
    }
};