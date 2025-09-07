class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>nums;
        if(n&1){
            nums.push_back(0);
            n--;
        }
        int cur = 1;
        for(int i = 0 ; i < n ; i+= 2){
            nums.push_back(cur);
            nums.push_back({-1*cur});
            cur++;
        }
      
        return nums;
    }
};