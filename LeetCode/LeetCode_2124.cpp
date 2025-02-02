class Solution {
public:
    bool checkString(string s) {
        auto it = find(s.begin(), s.end(), 'b');
        while (it != s.end()) {
            if (*it == 'a')
                return false;
            it++;
        }
        return true;
    }
};