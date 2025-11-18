class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int ind = 0;
        while(ind < n - 1){
            if(bits[ind] == 1) ind+= 2;
            else ind += 1;
        }
        return ind == n-1;
    }
};