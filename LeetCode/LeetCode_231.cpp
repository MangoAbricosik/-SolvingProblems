class Solution {
public:
    bool isPowerOfTwo(int n) {
        long power = 1;
        while (power <= n) {
            if (power == n)
                return true;
            power <<= 1;
        }
        return false;
    }
};