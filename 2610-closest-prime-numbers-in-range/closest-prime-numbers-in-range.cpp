class Solution {
public:
void sieve(int n,vector<bool> &is_prime) {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
     }
  }
    vector<int> closestPrimes(int left, int right) {
        if (left > right || right < 2) {
            return {-1, -1};
        }
        vector<bool> is_prime(right+1, true);
        sieve(right+1,is_prime);
        int prev = -1 ,num_1 = -1 , num_2 = -1;
        int mini = 1e8;
        for(int i = left ; i <= right ; i++){
              if(is_prime[i]){
                  if(prev != -1 && i-prev < mini){
                     mini = i - prev;
                     num_1 = prev;
                     num_2 = i;
                  }
                  prev = i;
              }
        }
        if(num_1 == -1) return {-1,-1};
      return {num_1,num_2};
    }
};