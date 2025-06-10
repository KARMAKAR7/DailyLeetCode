class Solution {
public:
    int maxDifference(string s) {
      vector<int>f(26,0);
      for(auto c:s){
          f[c-'a']++;
      }
      int mx = INT_MIN;
      int mn = INT_MAX;
      for(int i = 0 ; i < 26 ; i++){
          if(f[i] % 2 == 1){
             mx = max(f[i],mx);
          }
          else if (f[i] != 0 && f[i] % 2 == 0){
              mn = min( f[i] , mn);
          }else{
            continue;
          }
      }
      return mx - mn;
    }
};