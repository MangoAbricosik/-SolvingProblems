class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        std::sort(strs.begin(), strs.end(), [](const std::string& a, const std::string& b) {
            return a.size() < b.size();
            });

        string maxPrefix = strs[0];
        if (maxPrefix == "")
            return maxPrefix;

        size_t i = 1, y = 1;
        for (i = 1; i < strs.size(); i++) {
            for (y = 0; y < strs[i].size(); y++) {
                auto test1 = maxPrefix[y];
                auto test2 = strs[i][y];
                if (maxPrefix[y] != strs[i][y]) {
                    maxPrefix = maxPrefix.substr(0, y);
                    break;
                }
            }
        }

        return maxPrefix;
    }
};