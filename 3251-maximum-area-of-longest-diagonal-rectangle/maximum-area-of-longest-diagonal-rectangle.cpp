class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
       long long d2 = -1;
       long long  a = -1;
        for(int i = 0 ; i < dimensions.size();i++){
             long long l = dimensions[i][0];
             long long b = dimensions[i][1];
             long long d = l*l + b*b;
             long long area = l * b;
               if(d > d2){
                  d2 = d;
                  a = area;
               }else if(d == d2){
                    a = max(a,area);
               }
        }
        return (int)a;
    }
};