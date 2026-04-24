class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();
        int count = 0;
        int l = 0 , r = 0;
        for(auto ch:moves){
            if(ch == 'L') l++;
            if(ch == 'R') r++;
           }
        if(l == 0 && r == 0) return n;
        int x  = n - (l+r);
        if(l > r){
            return (l - r)+ x;
        }
        else
           return (r-l) + x;
    }
};