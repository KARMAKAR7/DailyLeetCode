class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int childOneCollect(vector<vector<int>>&fruits){
        int count = 0;
        for(int i = 0 ; i < n ;i++){
            count += fruits[i][i];
            dp[i][i] = 0;
            fruits[i][i] = 0;
        }
        return count;
    }
    int childSecondCollect(int i , int j ,vector<vector<int>>& fruits){
        if(i < 0 || i >= n || j < 0 || j >= n) return 0;
        if(i == n-1 && j == n-1){
            return 0;
        }
        if(i == j || i > j){
            return 0;
        }
         if (dp[i][j] != -1)
            return dp[i][j];

        int LeftCorner = fruits[i][j] + childSecondCollect(i+1 , j-1 , fruits);
        int middle = fruits[i][j] + childSecondCollect(i+1 , j , fruits);
        int RightCorner = fruits[i][j] + childSecondCollect(i+1 , j+1 , fruits);
        
        return dp[i][j] = max({LeftCorner,middle,RightCorner});
    }
    int childThridCollect(int i , int j ,vector<vector<int>>& fruits){
        if(i < 0 || i >= n || j < 0 || j >= n) return 0;

        if(i == n-1 && j == n-1){
            return 0;
        }
        if(i == j ||  j > i){
            return 0;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        int TopCorner = fruits[i][j] + childThridCollect(i-1 , j+1 , fruits);
        int Right = fruits[i][j] + childThridCollect(i , j+1, fruits);
        int RightCorner = fruits[i][j] + childThridCollect(i+1 , j+1 , fruits);
        
        return dp[i][j] = max({TopCorner,Right,RightCorner});
    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
       n =  fruits.size();
       dp.resize(n,vector<int>(n,-1));
       int first_Child = childOneCollect(fruits);
       int second_Child = childSecondCollect(0,n-1,fruits);
       int third_Child =  childThridCollect(n-1 ,0 , fruits);
       return first_Child + second_Child + third_Child; 
    }
};