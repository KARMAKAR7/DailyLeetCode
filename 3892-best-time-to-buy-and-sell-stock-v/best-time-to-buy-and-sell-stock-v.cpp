class Solution {
public:
    
    /*
    Thoghts->
    1.frist you the number of trnsaction should be at most k 
    this is the max limit

    2. we need to know the index and current no of transication
    have
*/

    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<vector<long long>>> memo(
            n, vector<vector<long long>>(k + 1, vector<long long>(3, -1)));

        function<long long(int, int, int)> dfs = [&](int i, int j,
                                                     int state) -> long long {
            if (j == 0) {
                return 0;
            }
            if (i == 0) {
                return state == 0 ? 0 : (state == 1 ? -prices[0] : prices[0]);
            }
            if (memo[i][j][state] != -1) {
                return memo[i][j][state];
            }

            int p = prices[i];
            long long res;
            if (state == 0) {
                res = max(dfs(i - 1, j, 0),
                          max(dfs(i - 1, j, 1) + p, dfs(i - 1, j, 2) - p));
            } else if (state == 1) {
                res = max(dfs(i - 1, j, 1), dfs(i - 1, j - 1, 0) - p);
            } else {
                res = max(dfs(i - 1, j, 2), dfs(i - 1, j - 1, 0) + p);
            }
            memo[i][j][state] = res;

            return res;
        };

        return dfs(n - 1, k, 0);
    }
};