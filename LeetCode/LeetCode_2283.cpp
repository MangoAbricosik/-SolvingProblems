class Solution {
public:
    bool digitCount(string num) {
        map<int, int> dict;
        for (auto item : num)
            dict[item - '0']++;

        for (size_t i = 0; i < num.size(); i++) {
            if (dict[i] != num[i] - '0')
                return false;
        }
        return true;
    }
};