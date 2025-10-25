class Solution {
public:
    int totalMoney(int n) {
        if(n <=7){
            return (n*(n+1))/2;
        }
        int start = 1,temp = 1;
        int ans = 0;
        for(int i = 1 ; i <= n ; i++){
              if(i%7 == 0){
                 ans += temp;
                 start++;
                 temp = start;
              }
              else{
                ans += temp;
                temp++;
                // cout << ans << " ";
              }
        }
        return ans;
    }
};