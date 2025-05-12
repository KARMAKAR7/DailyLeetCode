class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int>st;
        int n = digits.size();
        for(int i = 0  ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                for(int k = 0 ; k < n ; k++){
                      if(digits[i]==0) continue;
                      int digit = (digits[i]*100)+ (digits[j]*10) + digits[k];
                      if((i != j && j != k && i != k)&&(digit % 2 == 0) && st.find(digit) == st.end()){
                         st.insert(digit);
                      }
                }
            }
        }

        vector<int>res(st.begin(),st.end());
        return res;
    }
};