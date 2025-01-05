class Solution {
public:
    bool isPalindrome(int x) {
        std::string str = std::to_string(x);

        auto l = str.begin();
        auto r = (str.end() - 1);
        while (l <= r) {
            if (*l != *r)
                return false;
            l++;
            r--;
        }

        return true;
    }
};