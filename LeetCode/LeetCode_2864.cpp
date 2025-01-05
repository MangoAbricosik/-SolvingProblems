class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        sort(s.begin(), s.end());
        reverse(s.begin(), s.end());
        if (s.size() != 1 && *(s.end() - 1) == '0') {
            *(s.end() - 1) = '1';
            s.insert(s.size() - 1, "0");
            s.erase(s.begin());
        }
        return s;
    }
};