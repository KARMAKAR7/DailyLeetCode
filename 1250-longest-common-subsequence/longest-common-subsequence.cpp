class Solution {
public:
    //   int longestCommonSubsequence(string &text1, string &text2, int i, int j ,  vector<vector<int>>&dp) {
    //     if (i == text1.length() || j == text2.length())
    //         return 0;

    //     if(dp[i][j]!=-1){
    //         return dp[i][j];
    //     }
    //     if (text1[i] == text2[j])
    //       return dp[i][j]=1 + longestCommonSubsequence(text1, text2, i + 1, j + 1 ,dp);
    //     else
    //         return dp[i][j]= max(
    //             longestCommonSubsequence(text1, text2, i + 1, j ,dp),
    //             longestCommonSubsequence(text1, text2, i, j + 1 ,dp)
    //         );
    // }
    int longestCommonSubsequence(string text1, string text2) {
        vector<int>prev(text2.size()+1,0);
        for(int i = text1.length()-1 ; i >= 0 ; i--){
            vector<int>curr(text2.size()+1,0);
            for(int j = text2.length()-1 ; j >= 0 ; j--){
                if (text1[i] == text2[j])
                   curr[j] = 1 + prev[j + 1];
           else
                curr[j]= max(
                  prev[j],
                  curr[j+1]
                 );
            }
          prev = curr;
        }
       return prev[0];
    }
};