class Solution {
public:
    // int n;
    // unordered_map<string , int >dp;
    // int solve(int ind , int prev , string &colors,vector<int>&time){
    //     if(ind == n){
    //         return 0;
    //     }
    //     string key = to_string(ind) + "#" + to_string(prev);
    //     if(dp.find(key) != dp.end()) return dp[key];
    //     // we have two options if prev and currnet index have same color we need to take one of them
    //     if(colors[ind] == colors[prev]){
    //          int op1 = time[ind] + solve(ind+1,prev,colors,time);
    //          int op2 = time[prev] + solve(ind+1,ind,colors,time);
    //         return dp[key] = min(op1,op2);
    //     }
    //     else{
    //         return dp[key] = solve(ind+1,ind,colors,time);
    //     }
    // }
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        if(colors.empty()) return 0;
        // here greedy will work if we remove all the ballons except the maxinum one so it will be alwasy be
        // profitable  for us
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
                int j = i+1; // check further for the same segment
                int mxTime = neededTime[i];
                int sum = neededTime[i];
               while(j < n && colors[i] == colors[j]){
                  sum += neededTime[j];
                  mxTime = max(neededTime[j],mxTime);
                  j++;
               }
               cout << sum << " " << mxTime << " " << endl;
               ans += sum - mxTime; // becuse we remove all except one ballown
               i = j-1;
        }
        return ans;
    }
};