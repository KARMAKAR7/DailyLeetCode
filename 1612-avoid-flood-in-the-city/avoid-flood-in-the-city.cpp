class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, -1);
        unordered_map<int, int> lastRain; // lake -> last rain day
        set<int> dryDays; // available dry days
        
        for (int i = 0; i < n; i++) {
            if (rains[i] == 0) {
                // Store this dry day for future use
                dryDays.insert(i);
                ans[i] = 1; // default value, can be changed later
            } else {
                int lake = rains[i];
                
                // If this lake already has water, we need to dry it before today
                if (lastRain.find(lake) != lastRain.end()) {
                    // Find a dry day after the last rain on this lake and before today
                    auto it = dryDays.upper_bound(lastRain[lake]);
                    if (it == dryDays.end()) {
                        // No available dry day to prevent flood
                        return {};
                    }
                    
                    // Use this dry day to dry the lake
                    int dryDay = *it;
                    ans[dryDay] = lake;
                    dryDays.erase(it);
                }
                
                // Update the last rain day for this lake
                lastRain[lake] = i;
            }
        }
        
        return ans;
    }
};