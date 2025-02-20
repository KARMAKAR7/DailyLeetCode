class Solution {
public:
    unordered_map<int, unordered_map<int, int>> memo; 
    int dfs(vector<int>& strength,int k , int mask , int x){
     int n = strength.size();
     if(mask == (1 << n )-1) return 0;
     if(memo[mask].count(x)) return memo[mask][x];

     int minTime = INT_MAX;

     for(int i = 0 ; i < n ;i++){
        if(mask &(1 << i)) continue; // Skip if lock `i` is already broken
        int newMask = mask | (1<<i);
        int t = 0 , er = 0;

        while(er < strength[i]){ // // Simulate time to reach required energy
            t++;
            er+= x;
        }
        minTime = min(minTime , t+dfs(strength,k,newMask,x+k));
     }
     return memo[mask][x] = minTime;
    }
    int findMinimumTime(vector<int>& strength, int k) {
        memo.clear();
        return dfs(strength,k,0,1);
    }
};