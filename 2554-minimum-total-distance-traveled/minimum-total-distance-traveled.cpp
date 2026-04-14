class Solution {
public:
    #define ll long long
    vector<vector<ll>> dp;

    ll solve(int i, int j, vector<int>& robot, vector<vector<int>>& factory) {
        int n = robot.size();
        int m = factory.size();

        // all robots assigned
        if (i == n) return 0;

        // no factories left
        if (j == m) return 1e15;

        if (dp[i][j] != -1) return dp[i][j];

        ll res = 1e15;

        // Option 1: skip this factory
        res = solve(i, j + 1, robot, factory);

        // Option 2: take k robots from this factory
        ll cost = 0;
        int pos = factory[j][0];
        int limit = factory[j][1];

        for (int k = 0; k < limit && i + k < n; k++) {
            cost += abs(robot[i + k] - pos);
            res = min(res, cost + solve(i + k + 1, j + 1, robot, factory));
        }

        return dp[i][j] = res;
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        int n = robot.size();
        int m = factory.size();

        dp.assign(n + 1, vector<ll>(m + 1, -1));

        return solve(0, 0, robot, factory);
    }
};