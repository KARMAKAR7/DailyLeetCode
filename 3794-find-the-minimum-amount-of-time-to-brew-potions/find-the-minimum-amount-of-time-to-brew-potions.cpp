typedef long long ll;
class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        int m = mana.size();
        vector<long long>finishingTime(n,0);
        for(int j = 0 ; j < m ; j++){
            finishingTime[0] = finishingTime[0] + (long long)mana[j] * skill[0];

            for(int i = 1 ; i < n ; i++){
                 finishingTime[i]  = max(finishingTime[i],finishingTime[i-1]) + (long long) mana[j] * skill[i];
            }

            for(int i = n-1; i > 0 ; i--){
                 finishingTime[i-1]  = finishingTime[i] - (long long) mana[j] * skill[i];
            }
        }
        return finishingTime[n-1];
    }
};