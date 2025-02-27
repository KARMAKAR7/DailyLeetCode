class Solution {
public:
    int solve(int i , int j , vector<int>&arr,unordered_map<int,int>&EleToInd){
        int target = arr[j] - arr[i];
        if(EleToInd.count(target) && EleToInd.at(target) < i){
            int k = EleToInd.at(target);
            return solve(k,i,arr,EleToInd) + 1;
        }
       return 2;
    }
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int>EleToInd;

        for(int i = 0 ; i < arr.size();i++){
            EleToInd[arr[i]] = i;
        }
        int result = 0;
        for(int i = 1 ; i < n ; i++){
            for(int j = i+1 ; j < n ; j++){
               
                    int len = solve(i,j,arr,EleToInd);
                    if(len >= 3){
                        result = max(len,result);
                    }
            }  

        }
        return result ;
    }
};