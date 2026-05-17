class Solution {
public:
    bool solve(int ind , vector<int>&arr,int n ){
        if(ind < 0 || ind >= n || arr[ind] < 0) return false;

        if(arr[ind] == 0){
            return true;
        }
        bool choiceNxt = false;
        bool choicePrev = false;
        int step = arr[ind];
        arr[ind] = -arr[ind];
        if(ind + arr[ind] < n){
            choiceNxt = solve(ind + step,arr,n);
        }

        if(ind - arr[ind] >= 0){
            choicePrev = solve(ind - step,arr,n);
        }
        return choiceNxt || choicePrev;
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        return solve(start,arr,n);
    }
};