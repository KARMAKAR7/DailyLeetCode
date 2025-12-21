class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int rows = strs.size();
        int cols = strs[0].length();

        int count = 0;
        vector<bool> alreadySorted(rows, false);
        int row = 0;
        int col = 0;

        for(col = 0; col < cols; col++) {
            bool deleted = false;

            for(row = 0; row < rows-1; row++) {
                if(!alreadySorted[row] && strs[row][col] > strs[row+1][col]) {
                    count++;
                    deleted = true;
                    break; 
                }
            }

            if(deleted)
                continue;

            for(int row = 0; row < rows-1; row++) {
                alreadySorted[row] = alreadySorted[row] | (strs[row][col] < strs[row+1][col]);
            }
        }

        return count;
    }
};