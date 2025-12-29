class Solution {
public:
    unordered_map<string, bool> memo;
    bool dfs(string curr , string next , int idx,unordered_map<string,vector<char>>&mpp){
        if(curr.size() == 1) return true;
        
        if (idx == 0 && memo.count(curr))
            return memo[curr];
        if(next.size() == curr.size()-1){
             bool res =  dfs(next,"",0,mpp);
             memo[curr] = res;
             return res;
        }


        string key = curr.substr(idx,2);

        if(mpp.find(key) == mpp.end()) return false;

        for(char ch:mpp[key]){
            if(dfs(curr,next+ch,idx+1,mpp)){
                return true;
            }
        }
        return false;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string,vector<char>>mpp;
        for(auto &s:allowed){
              mpp[s.substr(0,2)].push_back(s[2]);
        }
        return dfs(bottom,"",0,mpp);
    }
};