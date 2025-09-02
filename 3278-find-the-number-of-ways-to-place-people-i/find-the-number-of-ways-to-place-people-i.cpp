class Solution {
public:

    int numberOfPairs(vector<vector<int>>& points) {
       int n = points.size();
       sort(points.begin(),points.end(),[](const vector<int>&a , const vector<int>&b){
         return a[0] == b[0] ? a[1] >b[1] : a[0] < b[0];
       });   
       int numnbersValid = 0;
       for(int top = 0 ; top < n - 1 ; top++){
           int btm = INT_MIN; // find the maximum buttom point
           for(int j = top+1 ; j < n ; j++){
                 if(points[j][1] <= points[top][1] && points[j][1] > btm){
                    numnbersValid++;
                    btm =  points[j][1];
                 }
           }
       }
       return numnbersValid;
    }
};