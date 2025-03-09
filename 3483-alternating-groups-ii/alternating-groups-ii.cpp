class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int i = 0 , j = 1;
        for(int i = 0 ; i < k-1; i++){
            colors.push_back(colors[i]);
        }
        int res = 0;
        while(j < (n+k-1)){
             
             if(colors[j]==colors[j-1]){
                i = j;
                j++;
                continue;
             }
             if(j-i+1 == k){
                res++;
                i++;
             }
          j++;
        }
      return res;
    }
};