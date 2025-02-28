class Solution {
public:
   vector<vector<int>> longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp;
    }

    string shortestCommonSupersequence(string str1, string str2) {
        vector<vector<int>> lcs = longestCommonSubsequence(str1, str2);
        string scs = "";
        int n = lcs.size();
        int m = lcs[0].size();
        int i = n-1, j = m-1;

        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                scs.push_back(str1[i - 1]);
                i--;
                j--;
            } 
            else if (lcs[i - 1][j] >= lcs[i][j - 1]) { // Fixed condition
                scs.push_back(str1[i - 1]);
                i--;
            } 
            else {
                scs.push_back(str2[j - 1]);
                j--;
            }
        }

        while (i > 0) {
            scs.push_back(str1[i - 1]);
            i--;
        }
        while (j > 0) {
            scs.push_back(str2[j - 1]);
            j--;
        }

        reverse(scs.begin(), scs.end());
        return scs;
    }
};
