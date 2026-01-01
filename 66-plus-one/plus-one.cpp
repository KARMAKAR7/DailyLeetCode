class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 1;
        vector<int>ans;
        for(int i = n - 1 ; i >= 0 ; i--){
              int nw = digits[i] + carry;
              ans.push_back(nw%10);
              carry =  nw / 10;
        }
        if(carry){
            ans.push_back(carry);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};