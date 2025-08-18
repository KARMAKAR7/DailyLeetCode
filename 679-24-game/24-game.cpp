class Solution {
public:
    // #define FLT_EPSLION std::numeric_limits<double>::epsilon
    const double FLT_EPSLION = 1e-6;
    vector<double>op(double a , double b){
        vector<double>opr;
        opr.push_back(a+b);
        opr.push_back(a*b);
        opr.push_back(a-b);
        opr.push_back(b-a);
        if(abs(b) > FLT_EPSLION)
               opr.push_back(a/b);
        if(abs(a) > FLT_EPSLION)
               opr.push_back(b/a);
      return opr;
    }
    bool solve(vector<double>&arr){
        int n = (int)arr.size();
        if(n==1){
            return abs(24.0 - arr[0]) <= FLT_EPSLION;
        }

        for(int fn = 0 ; fn < n ; fn++){
            for(int sn = 0 ; sn < n ; sn++){
                  if(fn == sn) continue;
                  double first_num = arr[fn];
                  double second_num = arr[sn];
                  vector<double>valid = op(first_num,second_num);
                //   vector<double>next;
                  for(auto it:valid){
                      vector<double> next;
                       next.push_back(it);
                       for(int i = 0 ; i < n ; i++){
                          if(i == fn || i == sn) continue;
                          next.push_back(arr[i]);
                       }
                       if(solve(next)) return true;
                  }
            }
        }
        return false;
    }
    bool judgePoint24(vector<int>& cards) {
        vector<double>arr(cards.begin(),cards.end());
        return solve(arr);
    }
};