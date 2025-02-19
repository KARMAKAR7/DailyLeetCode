class Solution {
public:
    void solve(int n , string &curr , vector<string>&res){
        if(curr.length() == n){
            res.push_back(curr);
            return;
        }

        for(char ch = 'a'; ch <= 'c' ; ch++){
            if(!curr.empty() && curr.back() == ch){
                continue;
            }

            curr.push_back(ch);
            solve(n,curr,res);
            curr.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        string curr = "";
        vector<string>res;
        solve(n,curr,res);
        if(res.size() < k) return "";
        return res[k-1];
    }
};