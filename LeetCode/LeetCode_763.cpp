class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<int, int> mp;
        vector<int> result;

        for (int i = 0; i < s.size(); ++i) {
            mp[s[i]] = i;
        }

        for (int i = 0, j = -1, nowMax = 0; i < s.size(); i++) {
            if ((nowMax = max(nowMax, mp[s[i]])) == i) {
                result.push_back(i - j);
                j = i;
            }
        }

        return result;
    }
};