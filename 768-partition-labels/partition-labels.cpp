class Solution {
public:
    vector<int> partitionLabels(string s) {
       int n = s.size();
       vector<int>lastInd(26,0);
       for(int i = 0 ; i < n ; i++){
          lastInd[s[i]-'a'] = i;
       }
       vector<int>result;
       int start = 0 , end = 0;
       for(int i = 0 ; i < n ; i++){
             end = max(end,lastInd[s[i]-'a']);
             if(i == end){ // we found its last index
                   result.push_back(end-start+1);
                   start = i+1;
             }
       }
      return result;
    }
};