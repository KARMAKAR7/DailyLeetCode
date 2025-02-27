class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int>EleToInd;
        vector<vector<int>>dp(n,vector<int>(n,2));
        for(int i = 0 ; i < arr.size();i++){
            EleToInd[arr[i]] = i;
        }
        int result = 0;
        for(int i = 1 ; i < n ; i++){
            for(int j = i+1 ; j < n ; j++){
                    int target = arr[j] - arr[i];
                    if(EleToInd.count(target) && EleToInd[target] < i){
                        int k = EleToInd[target];
                        dp[i][j] = dp[k][i] + 1;
                    }
                result = max(result , dp[i][j]);
            }  

        }
        return result >= 3 ? result :0;
    }
};