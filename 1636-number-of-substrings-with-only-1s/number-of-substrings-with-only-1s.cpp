class Solution {
public:
    int numSub(string s) {
       int n = s.length();
       long long ans = 0, cnt = 0;
       for(int i = 0 ; i < n ; i++){
            if(s[i] == '1'){
                cnt++;
            }
            else {
                // cout << cnt << " ";
                ans = ans + (cnt * (cnt + 1) / 2);
                cnt = 0;
            }
       }
       ans = ans + (cnt * (cnt + 1) / 2);
    //    cout << cnt << " ";
      return ans% 1000000007;;   
    }
};