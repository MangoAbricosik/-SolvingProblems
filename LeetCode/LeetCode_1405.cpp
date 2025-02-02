class Solution {
public:
    long long getSum(long long val) {
        if (val == 0)
            return 0;
        return val + getSum(val - 1);
    }

    int countHomogenous(string s) {
        char lastSym = s[0];
        long long result = 0;
        int counter = 1;

        for (size_t i = 1; i < s.size(); i++) {
            if (lastSym == s[i]) {
                counter++;
                continue;
            }
            result += getSum(counter);
            lastSym = s[i];
            counter = 1;
        }

        result += getSum(counter);
        lastSym = s[s.size() - 1];
        counter = 1;

        return result % 1000000007;
    }
};