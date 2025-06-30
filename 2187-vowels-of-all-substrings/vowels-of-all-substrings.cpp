class Solution {
public:
    long long countVowels(string word) {
       unordered_set<char>vol ={'a','e','i','o','u'};
       long long n = word.length();
       long long ans = 0;
       for(long long i = 0 ; i < n ; i++){
           if(vol.count(word[i])){
              ans += (i+1)*(n-i);
           }
       }
      return ans;
    }
};