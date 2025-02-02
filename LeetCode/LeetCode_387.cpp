class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, vector<int>> dict;
        for (size_t i = 0; i < s.size(); i++) {
            dict[s[i]].push_back(i);
        }

        int minIndex = INT_MAX;
        for (auto item : dict) {
            if (item.second.size() == 1) {
                minIndex = min(minIndex, item.second[0]);
            }
        }
        return minIndex == INT_MAX ? -1 : minIndex;
    }
};
