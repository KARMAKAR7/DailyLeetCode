class Solution {
public:
    long long solve(const string& str, const string& suffix, int limit) {
        if (str.length() < suffix.length())
            return 0;

        if (str.length() == suffix.length())
            return str >= suffix ? 1 : 0;

        long long count = 0;
        string trailing = str.substr(str.length() - suffix.length());
        int prefixLength = str.length() - suffix.length();

        for (int i = 0; i < prefixLength; ++i) {
            int digit = str[i] - '0';

            if (limit < digit) {
                count += pow(limit + 1, prefixLength - i);
                return count;
            } else {
                count += digit * pow(limit + 1, prefixLength - i - 1);
            }
        }

        if (trailing >= suffix)
            count++;

        return count;
    }

    long long numberOfPowerfulInt(long long start, long long finish, int limit, const string& s) {
        string startStr  = to_string(start - 1);
        string finishStr = to_string(finish);
        return solve(finishStr, s, limit) - solve(startStr, s, limit);
    }
};