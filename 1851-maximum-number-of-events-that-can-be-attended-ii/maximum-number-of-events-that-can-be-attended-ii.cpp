class Solution {
public:
    int n;
    vector<vector<int>> t;
    vector<int> startTimes;

    int binarySearchNext(vector<vector<int>>& events, int i) {
        int lo = i + 1, hi = n;
        int key = events[i][1];
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (events[mid][0] > key)
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }

    int solve(vector<vector<int>>& events, int i, int k) {
        if (k <= 0 || i >= n)
            return 0;

        if (t[i][k] != -1)
            return t[i][k];

        int take = events[i][2] + solve(events, binarySearchNext(events, i), k - 1);
        int skip = solve(events, i + 1, k);

        return t[i][k] = max(take, skip);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end()); // sort by start time
        n = events.size();
        t.assign(n + 1, vector<int>(k + 1, -1));
        return solve(events, 0, k);
    }
};

