class Solution {
public:
    int maxOperations(string s) {
        int res = 0 , ones = 0 , flg = false;
        for(auto ch : s){
             if(ch == '1'){
                ones++;
                flg = true;
             }
             else if(ch =='0' && flg){
                 res += ones;
                 flg = false;
             }
        }
        return res;
    }
};