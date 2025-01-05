class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string bin(32, ' ');

        for (size_t i = bin.size() - 1; i != -1; i--) {
            auto test = long(n - (pow(2, i)));
            if (long(n - (pow(2, i))) >= 0) {
                n -= pow(2, i);
                bin[i] = '1';
            }
            else {
                bin[i] = '0';
            }
        }

        reverse(bin.begin(), bin.end());
        n = 0;

        for (size_t i = bin.size() - 1; i != -1; i--) {
            if (bin[i] == '1')
                n += pow(2, i);
        }

        return n;
    }
};