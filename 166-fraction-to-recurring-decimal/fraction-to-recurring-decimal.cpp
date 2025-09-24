class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) {
            return "0";  // Any fraction with 0 numerator is 0
        }

        string result;

        // Determine the sign of the result
        if ((long long)numerator * (long long)denominator < 0) {
            result += '-';
        }

        // Work with absolute values to simplify division
        long long absNumerator   = labs(numerator);
        long long absDenominator = labs(denominator);

        // Integer part of the division
        long long integerPart = absNumerator / absDenominator;
        
        result += to_string(integerPart);

        // Initial remainder
        long long remainder = absNumerator % absDenominator;
        if (remainder == 0) {
            return result;  // No fractional part
        }

        // Fractional part begins
        result += '.';

        // Map to store remainder -> position in result string
        unordered_map<int, int> remainderPosition;

        while (remainder != 0) {
            // If this remainder was seen before, we found a repeating cycle
            if (remainderPosition.count(remainder)) {
                result.insert(remainderPosition[remainder], "(");
                result += ')';
                break;
            }

            // Store the position of this remainder
            remainderPosition[remainder] = result.size();

            // Simulate long division
            remainder *= 10;
            int digit = remainder / absDenominator;
            result += to_string(digit);

            remainder %= absDenominator;
        }

        return result;
    }
};
