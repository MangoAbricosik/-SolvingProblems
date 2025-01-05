class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        map<char, int> sMp;

        for (size_t i = 0; i < s.size(); i++) {
            if (!sMp.emplace(s[i], 1).second) {
                sMp[s[i]]++;
            }
        }

        map<char, int> targetMp;
        for (size_t i = 0; i < target.size(); i++) {
            if (!targetMp.emplace(target[i], 1).second) {
                targetMp[target[i]]++;
            }
        }

        vector<int> result;
        for (auto item : targetMp) {
            result.push_back(sMp[item.first] / item.second);
        }
        return *min_element(result.begin(), result.end());
    }
};