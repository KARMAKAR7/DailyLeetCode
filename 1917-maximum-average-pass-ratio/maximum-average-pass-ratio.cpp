class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extra) {
       priority_queue<pair<double,pair<int,int>>>heap;
       auto cal = [](int stu , int tot){
           return (double)(stu+1) /( tot+1 ) - (double)(stu)/(tot);
       };
       for(auto &cls:classes){
           int s = cls[0] , t = cls[1];
           double gain = cal(s,t);
           heap.push({gain,{s,t}});
       }
       while(extra--){
           auto [_,cls] = heap.top();
           heap.pop();
           int s = cls.first , t = cls.second;
           s++,t++;
           double g = cal(s,t);
           heap.push({g,{s,t}});
       }

       double avg = 0.0;

       while(!heap.empty()){
           auto [g,cls] = heap.top();
           heap.pop();
           avg += (double)cls.first/cls.second;
       }
       return avg/classes.size();
    }
};