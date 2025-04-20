class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<vector<int>>res;
        unordered_map<int,vector<int>>mpp; // {size,id}
        for(int i = 0 ; i < n ; i++){
           mpp[groupSizes[i]].push_back(i);
        }

        for(auto it:mpp){  // size --> vector;
           int count = it.second.size()/it.first;
           while(count--){
                vector<int>temp;
                for(int i = 0 ; i <it.first; i++){
                    int ele =  it.second.back();
                    it.second.pop_back();
                    temp.push_back(ele);
                }
                res.push_back(temp);
           }
        }
      return res;
    }
};