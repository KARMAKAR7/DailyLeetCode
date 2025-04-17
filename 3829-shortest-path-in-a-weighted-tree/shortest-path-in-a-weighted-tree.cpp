struct SegmentTree {
    int size;
    vector<long long> tree, lazy;

    void init(int n) {
        size = n;
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
    }

    void push(int node, int l, int r) {
        if (lazy[node] != 0) {
            tree[node] += lazy[node];
            if (l != r) {
                lazy[node * 2] += lazy[node];
                lazy[node * 2 + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void update(int node, int l, int r, int ql, int qr, int val) {
        push(node, l, r);
        if (qr < l || r < ql)
            return;
        if (ql <= l && r <= qr) {
            lazy[node] += val;
            push(node, l, r);
            return;
        }
        int mid = (l + r) / 2;
        update(node * 2, l, mid, ql, qr, val);
        update(node * 2 + 1, mid + 1, r, ql, qr, val);
    }

    long long query(int node, int l, int r, int idx) {
        push(node, l, r);
        if (l == r)
            return tree[node];
        int mid = (l + r) / 2;
        if (idx <= mid)
            return query(node * 2, l, mid, idx);
        else
            return query(node * 2 + 1, mid + 1, r, idx);
    }

    void update(int l, int r, int val) {
        update(1, 1, size, l, r, val);
    }

    long long query(int idx) {
        return query(1, 1, size, idx);
    }
};

class Solution {
public:
    map<pair<int,int>,int> mp;
    vector<pair<int,int>> adj[100001];
    vector<int> inTime, outTime, depth, parent;
    int timer = 1;

    void euler_dfs(int node, int par, int d) {
        inTime[node] = timer++;
        parent[node] = par;
        depth[node] = d;
        for (auto &it : adj[node]) {
            int child = it.first;
            int dist = it.second;
            if (child != par) {
                euler_dfs(child, node, d + dist);
            }
        }
        outTime[node] = timer++;
    }

    vector<int> treeQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        for (int i = 0; i <= n; i++) adj[i].clear();
        inTime.assign(n + 1, 0);
        outTime.assign(n + 1, 0);
        depth.assign(n + 1, 0);
        parent.assign(n + 1, 0);
        mp.clear();

        for (auto &it : edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
            mp[{min(u, v), max(u, v)}] = w;
        }

        timer = 1;
        euler_dfs(1, -1, 0);

        SegmentTree t;
        t.init(timer);

        vector<int> result;

        for (auto &it : queries) {
            int type = it[0];

            if (type == 2) {
                int x = it[1];
                result.push_back(depth[x] + t.query(inTime[x]));
            } else {
                int u = it[1];
                int v = it[2];
                int new_wt = it[3];
                int child = (parent[u] == v) ? u : v;
                pair<int, int> p = {min(u, v), max(u, v)};
                int old_wt = mp[p];
                int diff = new_wt - old_wt;
                t.update(inTime[child], outTime[child], diff);
                mp[p] = new_wt;
            }
        }

        return result;
    }
};
