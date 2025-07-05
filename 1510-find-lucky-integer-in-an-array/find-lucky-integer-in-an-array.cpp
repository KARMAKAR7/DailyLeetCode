class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>hash;
        int maxi = -1;
        for(auto it:arr){
            hash[it]++;
        }

        for(auto it :hash){
            if(it.first == it.second){
                maxi = max(it.first,maxi);
            }
        }
     return maxi;
    }
};