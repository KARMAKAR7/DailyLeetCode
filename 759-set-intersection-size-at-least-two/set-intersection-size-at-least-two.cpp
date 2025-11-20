class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1] || (a[1] == b[1] && a[0] > b[0]); 
        });
        int n = intervals.size(), ans = 0, p1 = -1, p2 = -1;
        for (int i = 0; i < n; i++) {
            if (intervals[i][0] <= p1) continue;
            if (intervals[i][0] > p2) {
                ans += 2;
                p2 = intervals[i][1];
                p1 = p2-1;
            }
            else {
                ans++;
                p1 = p2;
                p2 = intervals[i][1];
            }
        }
        return ans;
    }
};