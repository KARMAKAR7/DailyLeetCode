class Solution {
public:
    int n;
    int dp[100001][3];
    int bs(vector<vector<int>>&events , int endTime){
        int low = 0 , high = n - 1 , ans = n;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(events[mid][0] > endTime){
                 ans = mid;
                 high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
      return ans;
    }
    int helper(vector<vector<int>>&events , int ind , int count){
        if(count == 2 || ind >= n) return 0;
        if(dp[ind][count] != -1){
            return dp[ind][count];
        }
        int nxtInd = bs(events,events[ind][1]);
        int take = events[ind][2] + helper(events,nxtInd,count+1);
        int notTake = helper(events,ind+1,count);
        return dp[ind][count] = max(take,notTake);
        }
    int maxTwoEvents(vector<vector<int>>& events) {
        n = events.size();
        sort(events.begin(),events.end());
        memset(dp,-1,sizeof(dp));
        return helper(events,0,0);
    }
};