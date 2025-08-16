class Solution {
public:
    int maximum69Number (int num) {
        string n = to_string(num);
        string maxi = n;
        for(int i = 0 ; i < n.length() ; i++){
                char ch = n[i];
                n[i] = ch == '9'? '6' : '9';
                maxi = max(n,maxi);
                n[i] = ch;
        }
        return stoi(maxi);
    }
};