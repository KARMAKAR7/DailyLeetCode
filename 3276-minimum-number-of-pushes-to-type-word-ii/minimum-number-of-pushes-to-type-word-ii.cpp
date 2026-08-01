class Solution {
public:
    int minimumPushes(string word) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = word.size();
        unordered_map<char, int> mpp;
        for (int i = 0; i < n; i++) {
            mpp[word[i]]++;
        }

        vector<int> freqs;
        for (auto it : mpp) {
            freqs.push_back(it.second);
        }

        sort(freqs.begin(), freqs.end(), greater<int>());

        int ans = 0;
        for (int i = 0; i < freqs.size(); i++) {
             ans += (i / 8 + 1) * freqs[i];
        }

        return ans;
    }
};