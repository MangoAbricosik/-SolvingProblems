class Solution {
public:
    int smallestNumber(int n) {
        int result = 0, mask = 1;;
        while (result < n) {
            result |= mask;
            mask <<= 1;
        }
        return result;
    }
};