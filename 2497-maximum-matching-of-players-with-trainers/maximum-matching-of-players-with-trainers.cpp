class Solution {
public:
    bool possible(int k , vector<int>&players,vector<int>&trainers){
        multiset<int>ml(trainers.end()-k , trainers.end());
        for(int i = k - 1 ; i >= 0 ; i--){
            auto it = ml.lower_bound(players[i]);
            if(it == ml.end()) return false;
            ml.erase(it);
       }
      return true;
    }
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());

        int left = 0 , right = min(players.size(),trainers.size());
        int ans = 0;
        while(left <= right){
             int mid = left+(right - left)/2;

             if(possible(mid,players,trainers)){
                ans = mid;
                left = mid + 1;
             }else{
                right = mid - 1;
             }
        }
      return ans;
    }
};