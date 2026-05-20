class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n==1){
            return 0;
        }
        unordered_map<int,vector<int>>mpp;
        vector<int>vis(n,false);
        for(int i = 0 ; i < n ; i++){
            mpp[arr[i]].push_back(i); // number(7) -> indices (1,3,4,6) like thid
        }
        queue<int>q;
        q.push(0);
        vis[0] = true;
        int steps = 0;

        while(!q.empty()){
           int siz = q.size();
           while(siz--){
              int curInd = q.front();
               q.pop();
              if(curInd == n - 1) return steps;
              int left = curInd - 1;
              int right = curInd + 1;

              if(left >= 0 && !vis[left]){
                q.push(left);
                vis[left] = true;
              }
               if(right < n  && !vis[right]){
                q.push(right);
                vis[right] = true;
              }

              for(int &idx: mpp[arr[curInd]]){
                  if(!vis[idx]){
                    q.push(idx);
                     vis[idx] = true;
                  }
                }
               mpp.erase(arr[curInd]); 
           }
           steps++;
        }
        return -1;
    }
};