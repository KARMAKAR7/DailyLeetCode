class Solution {
public:
    vector<long long> distance(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> pos;
        pos.reserve(n * 2);
        for (int i = 0; i < n; ++i) pos[arr[i]].push_back(i);

        vector<long long> ans(n, 0);

        for (auto &entry : pos) {
            vector<int> &indices = entry.second;
            int m = indices.size();
            if (m == 1) continue;

            vector<long long> pre(m, 0), suff(m, 0);
            pre[0] = indices[0];
            for (int i = 1; i < m; ++i) pre[i] = pre[i-1] + indices[i];
            suff[m-1] = indices[m-1];
            for (int i = m-2; i >= 0; --i) suff[i] = suff[i+1] + indices[i];

            for (int k = 0; k < m; ++k) {
                long long idx = indices[k];

                long long left_sum = (k == 0) ? 0 : pre[k-1];
                long long left_count = k;
                long long left_dist = left_count * idx - left_sum;

                long long right_sum = (k == m-1) ? 0 : suff[k+1];
                long long right_count = m - 1 - k;
                long long right_dist = right_sum - right_count * idx;

                ans[idx] = left_dist + right_dist;
            }
        }

        return ans;
    }
};
