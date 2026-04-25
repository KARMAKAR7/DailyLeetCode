class Solution {
public:
    bool can(const vector<long long>& pos, int k, long long d, long long side) {
        int n = pos.size();
        long long P = 4LL * side;

        vector<long long> ext(2 * n);
        for (int i = 0; i < n; i++) {
            ext[i] = pos[i];
            ext[i + n] = pos[i] + P;
        }

        for (int start = 0; start < n; start++) {
            long long limit = ext[start] + P - d;  
            long long cur = ext[start];
            int cnt = 1;
            int idx = start;

            for (int take = 1; take < k; take++) {
                auto it = lower_bound(ext.begin() + idx + 1, ext.begin() + start + n, cur + d);
                if (it == ext.begin() + start + n) break;
                if (*it > limit) break;

                cur = *it;
                idx = it - ext.begin();
                cnt++;
            }

            if (cnt >= k) return true;
        }

        return false;
    }

    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long> pos;
        pos.reserve(points.size());

        for (auto &p : points) {
            long long x = p[0], y = p[1];
            if (y == 0) pos.push_back(x);
            else if (x == side) pos.push_back(1LL * side + y);
            else if (y == side) pos.push_back(3LL * side - x);
            else pos.push_back(4LL * side - y);
        }

        sort(pos.begin(), pos.end());

        long long low = 0, high = 2LL * side, ans = 0;
        while (low <= high) {
            long long mid = (low + high) / 2;
            if (can(pos, k, mid, side)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return (int)ans;
    }
};