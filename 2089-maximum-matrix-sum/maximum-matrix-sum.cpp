class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans = 0 , n = matrix.size();
        long long minElement = INT_MAX;
        long long negCount = 0;

        for(auto &row : matrix){
            for(auto &e : row){
                ans += abs(e);
                minElement = min(minElement,(long long) abs(e));
                if(e < 0) negCount++;
            }
        }
        if(negCount % 2 == 0) return ans;
        ans -= 2*minElement;
        return ans;   
    }
};