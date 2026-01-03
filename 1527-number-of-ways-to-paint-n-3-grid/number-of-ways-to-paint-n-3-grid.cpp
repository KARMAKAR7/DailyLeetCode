class Solution {
    int mod = 1e9 + 7;
public:
    int numOfWays(int n) {
        long long diff = 6, same = 6;

        for(int i = 1; i < n; i++) {
            long long s = (3*same + 2*diff)%mod;
            long long d = (2*same + 2*diff)%mod;

            same = s;
            diff = d; 
        }

        return (same + diff)%mod;
    }
};