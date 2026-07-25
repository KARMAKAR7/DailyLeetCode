class Solution {
public:
    int maxProduct(int n) {
        int maxi = -1;
        int s_maxi = -1;

        while (n) {
            int d = n % 10;

            if (d >= maxi) {
                s_maxi = maxi;
                maxi = d;
            } else if (d > s_maxi) {
                s_maxi = d;
            }

            n /= 10;
        }

        return maxi * s_maxi;
    }
};