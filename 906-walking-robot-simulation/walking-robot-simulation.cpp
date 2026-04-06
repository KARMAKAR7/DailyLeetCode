class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<pair<int,int>> dir ={{0,1},{1,0},{0,-1},{-1,0}}; // North, East, South, and West.
        long long x = 0 , y = 0 , dirIndex = 0;
        

        unordered_set<string> objset;
        for(const auto& obj : obstacles){
            string key = to_string(obj[0])+","+ to_string(obj[1]);
            objset.insert(key);
        }
        long long  maxD = 0;
        for(int cmd :commands){
            if(cmd == -2){
                dirIndex = (dirIndex+3)%4;
            }
            else if(cmd == -1){
                dirIndex = (dirIndex+1)%4;
            }else{
                for(int stp = 0 ; stp < cmd ; stp++){
                    long long  nx = x + dir[dirIndex].first;
                    long long ny = y +  dir[dirIndex].second;


                    string pos = to_string(nx)+","+to_string(ny);
                    if(objset.find(pos) == objset.end()){
                        x = nx;
                        y = ny;
                    maxD = max(maxD , x*x + y*y);
                    }else{
                        break;
                    }
                }
            }
        }
       return maxD;
    }
};