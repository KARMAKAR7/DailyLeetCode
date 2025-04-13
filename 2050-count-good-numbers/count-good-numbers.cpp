class Solution {
public:
    #define fio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
    using ll = long long;
    const ll m = 1e9 + 7;
    long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
    int countGoodNumbers(long long n) {
        fio;
        long long odd = n/2 , even = (n+1)/2;

        ll res = 0;
        res += binpow(5,even,m) * binpow(4,odd,m) % m ;
        return res;
    }
};