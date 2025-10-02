class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = 0;
        int full = numBottles;
        int empty = 0;
        int need = numExchange;

        while(full > 0 || empty >= need ){
            if(full > 0){
                ans += full;
                empty += full;
                full = 0;
            }

            while(empty >= need){
                empty -= need;
                full += 1;
                need += 1;
            }
        }
        return ans;
    }
};