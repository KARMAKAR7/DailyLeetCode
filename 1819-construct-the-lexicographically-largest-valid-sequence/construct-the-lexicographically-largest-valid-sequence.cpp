class Solution {
public:
    bool solve(int ind , int n , vector<int>&res,vector<bool>&vis){
         if(ind >= res.size()){
            return true;
         }
         if(res[ind] != 0){
            return solve(ind+1,n,res,vis);
         }
         for(int num = n ; num >= 1 ; num--){
            if(vis[num]){
                continue;
            }

            res[ind] = num;
            vis[num] = true;

            if(num == 1){
                if(solve(ind+1 , n , res , vis)){
                    return true;
                }
            }
            else{
                 int nxInd = ind+num;
                 if(nxInd < res.size() && res[nxInd] == 0){
                     res[nxInd] = num;
                     if(solve(ind+1,n,res,vis)){
                        return true;
                     }
                    res[nxInd] = 0;
                 }
            }
            res[ind] = 0;
            vis[num] = false;
         }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        vector<int>res(2*n-1,0);
        vector<bool>vis(n+1,false);
        solve(0,n,res,vis);
        return res;
    }
};