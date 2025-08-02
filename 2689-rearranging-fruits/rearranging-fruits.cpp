class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> mp;
        int minEl = INT_MAX;
        for(int &x : basket1) {
            mp[x]++;
            minEl = min(minEl, x);
        }

        for(int &x : basket2) {
            mp[x]--;
            minEl = min(minEl, x);
        }

        vector<int> finalList;
        for(auto &it : mp) {
            if(it.second == 0) continue;

            if(it.second % 2 != 0)
                return -1;
            
            for(int count = 0; count < abs(it.second)/2; count++) {
                finalList.push_back(it.first);
            }
        }

        sort(begin(finalList), end(finalList));

        long long cost = 0;
        for(int i = 0; i < finalList.size()/2; i++) {
            cost += min(finalList[i], 2*minEl);
        }

        return cost;
    }
};