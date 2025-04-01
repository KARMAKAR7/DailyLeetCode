class Solution {
public:
    // long long findmostPoints(int ind , vector<vector<int>>& questions, int n ,vector<long long>&dp){
    //     if(ind >= n){
    //         return 0;
    //     }
    //     if(dp[ind]!=0) return dp[ind];
    //     long long take  = questions[ind][0] + findmostPoints(ind+questions[ind][1]+1,questions , n,dp);
    //     long long nottake = 0 + findmostPoints(ind+1,questions,n,dp);
        
    //     return dp[ind]= max(take,nottake);
    //     }

    long long mostPoints(vector<vector<int>>& questions) {
          int n=questions.size();
        vector<long long> dp(n+1,0);
            for(int ind=n-1;ind>=0;ind--){
                long long take=0;
                if(ind+questions[ind][1]+1>=n)
                take=questions[ind][0]+dp[n];
                else take=questions[ind][0]+dp[ind+questions[ind][1]+1];    
                long long notTake=dp[ind+1];
                dp[ind]=max(take,notTake);
    }   
    return dp[0];
    }
};