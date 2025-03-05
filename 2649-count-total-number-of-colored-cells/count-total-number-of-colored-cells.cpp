class Solution {
public:
    long long coloredCells(int n) {
        long long ans = 1;
        int mul = 4;
        while(--n){
           ans+= mul;
           mul += 4;
        }
    return ans;
    }
};