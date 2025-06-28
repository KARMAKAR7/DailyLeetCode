class Solution {
public:
    long long getSquareFreePart(int x) {
        long long result = 1;
        for (int d = 2; d * d <= x; ++d) {
            long long count = 0;
            while (x % d == 0) {
                x /= d;
                count++;
            }
            // If exponent is odd, include the prime once
            if (count % 2 == 1) {
                result *= d;
            }
        }
        // If x is a leftover prime > sqrt(x), it contributes once
        if (x > 1) result *= x;
        return result;
    }
    long long maximumSum(vector<int>& nums) {
        unordered_map<long long, long long > groupSum;
        int n = nums.size();
        for (int i = 1; i <= n; ++i) {
            long long squareFree = getSquareFreePart(i);
            groupSum[squareFree] += nums[i - 1];  // 1-indexed adjustment
        }

        long long maxSum = 0;
        for (auto& [key, sum] : groupSum) {
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};