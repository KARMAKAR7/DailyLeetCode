class Solution {
public:
    unordered_set<int> visited;
    unordered_set<int> foundBoxes;

    int dfs(int box, vector<int>& status, vector<int>& candies,
            vector<vector<int>>& keys, vector<vector<int>>& containedBoxes) {
        
        if (visited.count(box)) 
            return 0;

        if (status[box] == 0) {
            foundBoxes.insert(box);
            return 0;
        }

        visited.insert(box);
        int total = candies[box];

        for (int insideBox : containedBoxes[box]) {
            total += dfs(insideBox, status, candies, keys, containedBoxes);
        }

        for (int boxKey : keys[box]) {
            status[boxKey] = 1;
            if (foundBoxes.count(boxKey)) {
                total += dfs(boxKey, status, candies, keys, containedBoxes);
            }
        }

        return total;
    }

    int maxCandies(vector<int>& status, vector<int>& candies,
                   vector<vector<int>>& keys, vector<vector<int>>& containedBoxes,
                   vector<int>& initialBoxes) {

        int result = 0;
        for (int& box : initialBoxes) {
            result += dfs(box, status, candies, keys, containedBoxes);
        }
        return result;
    }
};
