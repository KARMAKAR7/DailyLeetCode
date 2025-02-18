class Solution {
public:
    bool mathaches(string & res , string & pattern){
        for(int i = 0 ;i < pattern.length();i++){
            if((pattern[i] == 'I' && res[i] > res[i+1])||
               (pattern[i] == 'D' && res[i] < res[i+1])){
                   return 0;
            }
        }
        return 1;
    }
    string smallestNumber(string pattern) {
        int n = pattern.length();
        string res ="";
        for(int i =1 ; i <= n+1 ; i++){
           res.push_back(i+'0'); 
        }

        while(!mathaches(res,pattern)){
            next_permutation(res.begin(),res.end());
        }
        return res;
    }
};