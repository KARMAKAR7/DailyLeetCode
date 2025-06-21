class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int>freq(26,0);
        for(auto ch : word){
             freq[ch-'a']++;
        }
        int minideletion = INT_MAX;
        for(int i = 0 ; i < 26 ; i++){
             int currdeletion = 0;
             for(int j = 0 ; j < 26 ; j++){
                   if(i == j) continue;
                   else{
                        if(freq[j] < freq[i]){
                            currdeletion += freq[j];
                        }else if(abs(freq[j] - freq[i]) > k){
                                currdeletion += abs(freq[j] - freq[i] - k);
                        }
                   }
             }
             minideletion = min(minideletion,currdeletion);
        }
      return minideletion;
    }
};