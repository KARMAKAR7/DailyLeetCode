class Solution {
public:
    bool possilbe(string &s , string &t , int k){
        int n = t.length();
        int i = 0 , j = 0;

        while(i < s.length()){
            if(s[i]==t[j%n]){
                j++;
            }
            i++;
        }
      return j >= k*n;
    }
    //  solve(s,can,maxf,string res,"");
    void solve(string &s , vector<bool>&can , vector<int>&maxf,string &res,string curr,int maxlen,int k){
        if(curr.length() > maxlen) return;
        if(((curr.length() > res.length()) || ((curr.length() == res.length()) && (curr > res))) && possilbe(s,curr,k)){
            res = curr;
        }
     
        for(int i = 25; i >= 0 ; i--){
            if(can[i] == false || maxf[i] == 0) continue;

            maxf[i]--;
            curr.push_back(i+'a');
            solve(s,can,maxf,res,curr,maxlen,k);
            curr.pop_back();
            maxf[i]++;
        }
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        vector<int>freq(26,0);
        for(char &ch:s){
            freq[ch-'a']++;
        }

        vector<int>maxf(26,0);
        vector<bool>can(26,false);
        for(int i = 0 ; i < 26 ; i++){
            if(freq[i] >=k){
                maxf[i] = freq[i] / k;
                can[i] = true;
            }
        }
        int maxlen = s.length()/k;
        string res = "";
        solve(s,can,maxf,res,"",maxlen,k);
        return res;
    }
};