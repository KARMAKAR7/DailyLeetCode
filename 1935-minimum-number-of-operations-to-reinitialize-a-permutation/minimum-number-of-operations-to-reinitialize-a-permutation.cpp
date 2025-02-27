class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int>perm(n),ori(n);
        for(int i = 0 ; i < n ; i++){
            perm[i] = ori[i] = i;
        }
      
        vector<int>temp(n);
        int count = 0;
        while(true){
           for(int i = 0 ; i < n ; i++){
                if(i%2) temp[i] = perm[n / 2 + (i - 1) / 2];
                else temp[i] = perm[i / 2];
           }
           count++;
           perm = temp;

           if(perm == ori){
            break;
           }
        }
       return count;
    }
};