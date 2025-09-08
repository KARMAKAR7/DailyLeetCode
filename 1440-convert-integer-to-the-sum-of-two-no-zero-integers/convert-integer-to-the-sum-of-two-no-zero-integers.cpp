class Solution {
public:
    bool fun(int n){
        while(n){
            int dig = n%10;
            if(dig == 0) return false;
            n = n/10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int i = 1 ; i < n ; i++){
             if(fun(i) && fun(n-i)){
                return {i,n-i};
             }
        }
        return {-1,-1};
    }
};