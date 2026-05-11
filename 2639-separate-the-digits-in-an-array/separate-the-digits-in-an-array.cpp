class Solution {
public:
    void find(int n,vector<int>&res){
        vector<int>temp;
        while(n){
            int dig = n % 10;
            temp.push_back(dig);
            n = n / 10;
        }
        for(int i = temp.size()-1; i >= 0 ; i--){
               res.push_back(temp[i]);
        }
    }
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        for(int n:nums){
            find(n,ans);
        }
        return ans;
    }
};