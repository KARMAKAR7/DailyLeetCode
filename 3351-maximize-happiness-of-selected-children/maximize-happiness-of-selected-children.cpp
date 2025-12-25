class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end(),greater<int>());
        long long ans = 0;
        long long count = 0;
        for(int i = 0 ; i < happiness.size();i++){
             ans += max(0LL,happiness[i]-count);
             count += 1;
             if(count >= k){
                break;
             }
        }
    return ans;
    }
};