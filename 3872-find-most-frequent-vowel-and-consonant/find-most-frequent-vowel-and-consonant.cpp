class Solution {
public:
    int maxFreqSum(string s) {
     map<char,int>v;
     map<char,int>c;
     for(auto ch :s){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o'|| ch=='u'){
            v[ch]++;
        }else{
            c[ch]++;
        }
     }
     int maxv = 0 , maxc = 0;
     for(auto it:v) maxv = max(maxv,it.second);
     for(auto it:c) maxc = max(maxc,it.second);
     return maxv + maxc;
    }
};