class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int>ans;

        for(auto ele:nums){
            while(!ans.empty()){
                 int prev = ans.back();
                 int gc = gcd(prev,ele);

                 if(gc == 1){
                     break;
                 }
                ans.pop_back();
                int lcm = prev / gc * ele;
                ele = lcm; 
            }
            ans.push_back(ele);
        }
      return ans;
    }
};