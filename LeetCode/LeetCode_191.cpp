class Solution {
public:
    int hammingWeight(int n) {
        int result = 0;
        for (size_t i = 32 - 1; i != -1; i--) {
            if (long(n - (pow(2, i))) >= 0) {
                n -= pow(2, i);
                result++;
            }
        }

        return result;
    }
};