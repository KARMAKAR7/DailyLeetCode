class Solution {
public:
    int solve(int num, int mask , int n){
          if(num == n) return 1;
          // try all digits
          int ans = 0;
          for(int i = 0; i <= 9 ; i++){
             if(num == 0 && i == 0) continue;
              if((mask & (1<<i)) == 0){
                   ans += solve(num+1 , mask | (1<<i) , n);
              }
          }
        return ans;
    }
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        if (n == 1) return 10;
        int total = 1; 
        for (int L = 1; L <= n && L <= 10; ++L) {
            total += solve(0, 0, L);
        }
        return total;
    }
};