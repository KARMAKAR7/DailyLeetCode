class Solution {
public:
    bool isPowerOfTwo(long long x) {
    return x > 0 && (x & (x - 1)) == 0;
    }
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
    sort(s.begin(), s.end());
    do {
        if (s[0] != '0') {
            long long num = stoll(s);
            if (isPowerOfTwo(num)) return true;
        }
    } while (next_permutation(s.begin(), s.end()));
    return false;
    }
};