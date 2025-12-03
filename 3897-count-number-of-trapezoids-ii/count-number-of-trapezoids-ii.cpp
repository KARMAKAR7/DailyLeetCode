class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();

        unordered_map<float, vector<float>> slopeToIntercepts;

        unordered_map<int, vector<float>> midpointToSlopes;

        int result = 0;

        for (int i = 0; i < n; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];

            for (int j = i + 1; j < n; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];

                int dx = x1 - x2;
                int dy = y1 - y2;

                float slope, intercept;

                // Vertical line - Infinite Slope
                if (x1 == x2) {
                    slope     = 1e9 + 7; //Assign a large value to represent infinity
                    intercept = x1;      //general line formula is y = mx+c, where c is the y-intercept but here there is not y intercept
                } else {
                    slope     = (float)(y2 - y1) / (x2 - x1);
                    intercept = (float)(y1 * dx - x1 * dy) / dx; //general line formula is y = mx+c, derive from here
                }

                int midpointKey = (x1 + x2) * 10000 + (y1 + y2);

                slopeToIntercepts[slope].push_back(intercept);
                midpointToSlopes[midpointKey].push_back(slope);
            }
        }

        for (auto& [slope, interceptList] : slopeToIntercepts) {
            if (interceptList.size() <= 1) 
                continue;

            map<float, int> mp;  
            for (float b : interceptList) {
                mp[b]++;
            }

            int prevCount = 0;
            for (auto& it : mp) {
                int count = it.second;
                result    += count * prevCount;
                prevCount += count;
            }
        }

        for (auto& [midKey, slopeList] : midpointToSlopes) {
            if (slopeList.size() <= 1) continue;

            map<float, int> freq; // slope -> count
            for (float k : slopeList) freq[k]++;

            int prefix = 0;
            for (auto& [_, count] : freq) {
                result -= prefix * count;
                prefix += count;
            }
        }

        return result;
    }
};