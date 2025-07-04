class Solution {
public:
    typedef long long ll;
    char kthCharacter(long long k, vector<int>& operations) {
         if(k==1){
            return 'a';
         }
        ll n = operations.size();
        ll len = 1;
        ll newK = -1;
        ll opType = -1;

        for(ll i = 0 ; i < n ; i++){
            len *= 2;
            if(len >= k){
                  opType = operations[i];
                  newK = k - len/2;
                  break;
            }
        }
       
        char ch = kthCharacter(newK , operations);

        if(opType == 0){
            return ch;
        }
       
      return ch == 'z' ? 'a' : ch+1;
    }
};