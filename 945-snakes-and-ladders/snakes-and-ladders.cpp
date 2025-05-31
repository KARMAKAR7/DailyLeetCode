class Solution {
public:
    int n ;
    pair<int,int> getCordinates(int s){
        int row = n-1-(s-1)/n;
        
        int col = (s-1)%n;
        
        if((n%2==1 && row%2==1)||(n%2==0 && row%2==0))
            col = n-1-col;
        
        return make_pair(row, col);
    }
    int snakesAndLadders(vector<vector<int>>& board) {
      n = board.size();
      int steps = 0;
      queue<int>q;
      vector<vector<bool>>vis(n , vector<bool>(n,false));
      vis[n-1][0] = true;
      q.push(1);

      while(!q.empty()){
        int N = q.size();

        while(N--){
            int x = q.front();
            q.pop();

            if(x == n*n){
              return steps;
             }

          for(int i = 1 ; i<=6 ; i++){
              int val = x+i;

              if(val > n*n){
                break;
              }

            pair<int,int>cord = getCordinates(val);
            int x = cord.first;
            int y = cord.second;

             if(vis[x][y] ==true) continue;
             
             vis[x][y] = true;
              if(board[x][y] != -1){
               q.push(board[x][y]);
                }
               else{
                 q.push(val);
               }
             }
          }
          steps++;
       }
      return -1;
    }
};