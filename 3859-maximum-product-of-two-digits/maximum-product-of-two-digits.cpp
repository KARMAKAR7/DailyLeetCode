class Solution {
public:
    int maxProduct(int n) {
      string num = to_string(n);
      sort(num.begin(),num.end());
      int s = num.size();
      int d1 = num[s-2]-'0';
      int d2 = num[s-1]-'0';
      return d1*d2;
    }
};