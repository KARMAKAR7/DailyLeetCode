class Solution {
public:
    int N;
    int maxTime;
    vector<vector<vector<int>>> dp;

    int solve(int index, int k, int currentTime, vector<int>& position, vector<int>& time) {
        if (index == N - 1) {
            return (k > 0) ? INT_MAX : 0;
        }

        if (dp[index][k][currentTime] != -1) {
            return dp[index][k][currentTime];
        }

        int result = INT_MAX;

        // Option 1: Don't merge, move to index + 1
        int skip = solve(index + 1, k, time[index + 1], position, time);
        if (skip != INT_MAX) {
            int dist = position[index + 1] - position[index];
            result = min(result, currentTime * dist + skip);
        }

        // Option 2: Merge from index+1 to index+2, ..., up to k merges allowed
        if (k > 0) {
            int mergedRate = time[index + 1];
            int mergeCount = 0;
            for (int next = index + 2; next < N && mergeCount < k; ++next) {
                mergedRate += time[next];
                mergeCount++;

                int nextResult = solve(next, k - mergeCount, mergedRate, position, time);
                if (nextResult != INT_MAX) {
                    int dist = position[next] - position[index];
                    result = min(result, currentTime * dist + nextResult);
                }
            }
        }

        return dp[index][k][currentTime] = result;
    }

    int minTravelTime(int l, int n, int k, vector<int>& position, vector<int>& time) {
        N = n;
        maxTime = 0;
        for (int t : time) maxTime += t;  // Max possible merged rate

        // Initialize dp with -1
        dp = vector<vector<vector<int>>>(
            N, vector<vector<int>>(k + 1, vector<int>(maxTime + 1, -1))
        );

        return solve(0, k, time[0], position, time);
    }
};
