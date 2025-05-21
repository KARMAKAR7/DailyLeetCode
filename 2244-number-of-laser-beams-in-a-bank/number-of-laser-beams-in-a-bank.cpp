class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> devicesPerRow;
        
        for (const string& row : bank) {
            int count = count_if(row.begin(), row.end(), [](char c) { return c == '1'; });
            if (count > 0) {
                devicesPerRow.push_back(count);
            }
        }

        int totalBeams = 0;
        for (int i = 1; i < devicesPerRow.size(); ++i) {
            totalBeams += devicesPerRow[i - 1] * devicesPerRow[i];
        }

        return totalBeams;
    }
};
