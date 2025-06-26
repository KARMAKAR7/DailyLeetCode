class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.length()-1;
        int result = 0;
        int value = 0;
        for(int i = n ; i >= 0 ; i--){
              if(s[i] == '0'){
                result++;
              }else{
                  if((n-i+1 < 31) && (value + (1<<(n-i))) <=k){
                        value += (1<<(n-i));
                        result++;
                  }
              }
        }
      return result;
    }
};