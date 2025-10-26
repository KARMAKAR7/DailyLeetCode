class Solution {
public:
    long long removeZeros(long long n) {
        string s = to_string(n);
        string ans;
        for(auto i :s){
            if(i != '0'){
                ans +=i;
            }
        }
        return stol(ans);
    }
};