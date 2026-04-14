class Solution {
public:
    #define ll long long
    vector<vector<ll>> dp;
    ll solve(int robotIdx , int factoryIdx , vector<int>&robot , vector<int>&FactPositions,int n , int m){
        if(robotIdx == n) return 0;
        if(factoryIdx == m) return 1e12;
        if(dp[robotIdx][factoryIdx] != -1) return dp[robotIdx][factoryIdx]; 
        ll take = abs(robot[robotIdx] - FactPositions[factoryIdx]) + solve(robotIdx+1 , factoryIdx+1 , robot,FactPositions,n,m);
        ll skip = solve(robotIdx ,factoryIdx+1 , robot , FactPositions,n,m);

        return dp[robotIdx][factoryIdx]= min(take,skip);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int n = robot.size();
        // sort the robots and factories by their positions becuase we need to find the near factory
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());

        vector<int>FactPositions;
        for(auto fact:factory){
            for(int i = 0 ; i < fact[1] ; i++){
                FactPositions.push_back(fact[0]);
            }
        }
        int m = FactPositions.size();
        dp.assign(n + 1, vector<ll>(m + 1, -1));
        return solve(0,0,robot,FactPositions,n,m);
    }
};