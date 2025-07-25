class Solution {
public:
    #define ll long long 
    const int mod = 1e9 + 7;

    // DP: index, tight, previous digit, validNumStarted
    ll dp[101][2][10][2];

    ll fun(int index, bool tight, int prev, bool validNum, string &s) {
        if (index == s.size()) {
            return validNum ? 1 : 0;
        }

        if (dp[index][tight][prev][validNum] != -1) {
            return dp[index][tight][prev][validNum];
        }

        ll ans = 0;
        int limit = tight ? s[index] - '0' : 9;

        for (int d = 0; d <= limit; d++) {
            bool newTight = tight && (d == limit);
            if (!validNum && d == 0) {
                // Still leading zeros
                ans = (ans + fun(index + 1, newTight, prev, false, s)) % mod;
            } else if (!validNum && d > 0) {
                // First non-zero digit
                ans = (ans + fun(index + 1, newTight, d, true, s)) % mod;
            } else if (abs(d - prev) == 1) {
                // Valid stepping step
                ans = (ans + fun(index + 1, newTight, d, true, s)) % mod;
            }
        }

        return dp[index][tight][prev][validNum] = ans;
    }

    // Check if a given number string is a stepping number
    bool isStepping(string &s) {
        if (s.size() == 1) return true;  // Single-digit numbers are stepping by default
        for (int i = 1; i < s.size(); i++) {
            if (abs((s[i] - '0') - (s[i - 1] - '0')) != 1) {
                return false;
            }
        }
        return true;
    }

    int countSteppingNumbers(string low, string high) {
        memset(dp, -1, sizeof(dp));
        ll countLow = fun(0, true, 0, false, low);

        if (isStepping(low)) {
            countLow--;  // Don't count low itself when subtracting
        }

        memset(dp, -1, sizeof(dp));
        ll countHigh = fun(0, true, 0, false, high);

        return ((countHigh - countLow) % mod + mod) % mod;
    }
};
