class Solution {
public:
    int maxPower(string s) {
        char lastSym = s[0];
        int counter = 1, result = 1;
        for (size_t i = 1; i < s.size(); i++) {
            if (lastSym == s[i]) {
                counter++;
                result = max(result, counter);
                continue;
            }
            lastSym = s[i];
            counter = 1;
        }
        return result;
    }
};