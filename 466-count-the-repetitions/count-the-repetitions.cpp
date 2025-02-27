class Solution {
public:
    int solve(string &s1, int n1, string &s2, int n2 , int count_s1 , int next_ind_s2 , int count_s2){
        if(count_s1 == n1) return count_s2/n2;
        
        int len1 = s1.length() , len2 = s2.length();
        int new_c_s2 = count_s2;
        int new_ind_s2 = next_ind_s2;
        
        for(char c:s1){
            if(c == s2[new_ind_s2]){
                new_ind_s2++;
                if(new_ind_s2 == len2){
                    new_c_s2++;
                    new_ind_s2 = 0;
                }
            }
        }
    return solve(s1,n1,s2,n2,count_s1+1,new_ind_s2,new_c_s2);
    }
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        return solve(s1,n1,s2,n2,0,0,0);
    }
};