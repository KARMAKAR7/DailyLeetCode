class Solution {
public:
    using ll = long long;
    long long countGoodIntegers(int n, int k) {
         unordered_set<string>st;

         ll d = (n+1)/2;
         ll s = pow(10,d-1);
         ll e = pow(10,d)-1;
         
         for(int num = s ; num<= e ; num++){
                string left = to_string(num);
                string full = "";
                if(n%2 == 0){
                    string right = left;
                    reverse(right.begin(),right.end());
                    full = left + right;
                }
                else{
                     string right = left.substr(0,d-1);
                       reverse(right.begin(),right.end());
                       full = left + right;
                }
            ll no = stoll(full);
            if(no % k != 0) continue;

            sort(full.begin(),full.end());
            st.insert(full);
         } 
        ll res = 0;
        vector<ll>fact(11,1);

        for(int i = 1 ; i < 11 ; i++){
            fact[i] = fact[i-1] * i;
        }
         for(auto &s:st){
            vector<int>count(10,0);
            for(auto &ch : s){
                count[ch-'0']++;
            }
            
            ll toltalD = s.length();
            ll z = count[0];

            ll nZ = toltalD  - z ;

            ll prem = (nZ * fact[toltalD-1]); 
            
            for(int i = 0 ; i < 10 ; i++){
                prem /= fact[count[i]];
            }

           res += prem;
         }
       return res;
    }
};