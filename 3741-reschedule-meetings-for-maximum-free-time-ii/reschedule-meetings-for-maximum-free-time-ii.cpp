class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {

        vector<int> freeArray; //store durations of free gaps

        //ith event
        //ith start - (i-1)th ka end = free gap duration
        freeArray.push_back(startTime[0]);

        for(int i = 1; i < startTime.size(); i++) {
            freeArray.push_back(startTime[i] - endTime[i-1]);
        }

        freeArray.push_back(eventTime - endTime[endTime.size()-1]);

        // Step 2: Precompute the largest free time to the right of each index
        int n = freeArray.size();
        vector<int> maxRight(n, 0);
        for (int i = n - 2; i >= 0; i--) {
            maxRight[i] = max(maxRight[i + 1], freeArray[i + 1]);
        }

        vector<int> maxLeft(n, 0);
        for (int i = 2; i < n; i++) {
            maxLeft[i] = max(maxLeft[i - 1], freeArray[i - 2]);
        }

        // Step 3: Try moving each meeting and calculate max free time
        int result = 0;
        for (int i = 1; i < n; ++i) {
            int curMeetingDuration = endTime[i - 1] - startTime[i - 1];  // Duration of the (i-1)th meeting

            //Move the meeting to another free spot
            //But, check if moving is possible or not
            if (curMeetingDuration <= max(maxLeft[i], maxRight[i])) {
                result = max(result, freeArray[i - 1] + curMeetingDuration + freeArray[i]);
            }

            //Merge left and right free time
            result = max(result, freeArray[i - 1] + freeArray[i]);
        }

        return result;
    }
};