class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size();
          int count = 0;
          unordered_map<int,int>mpp;
          for(int i = 0 ; i < n ; i++){
                mpp[answers[i]]++;
          }

          for(auto it:mpp){
             int g_size = it.first + 1 ;
             int total_g = ((it.second + g_size - 1)/g_size);  // for ceil 
             count += g_size * total_g;
          }
      return count;
    }
};