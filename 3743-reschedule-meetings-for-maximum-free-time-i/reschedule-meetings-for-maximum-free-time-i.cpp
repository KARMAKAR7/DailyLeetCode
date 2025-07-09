class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> gapArray;

        gapArray.push_back(startTime[0]);

        for (int i = 1; i < startTime.size(); ++i) {
            gapArray.push_back(startTime[i] - endTime[i - 1]);
        }
        
        gapArray.push_back(eventTime - endTime.back());

        int maxSum = 0;
        int currSum = 0;
        int i = 0;
        int j = 0;
        int n = gapArray.size();
        while (j < n) {
            currSum += gapArray[j];

            while(i < n && j - i + 1 > k + 1) {
                currSum -= gapArray[i];
                i++;
            }

            maxSum = max(maxSum, currSum);
            j++;
        }

        return maxSum;

    }
};