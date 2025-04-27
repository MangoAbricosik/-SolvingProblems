class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        vector<int> prefix(1, 1);
        for (size_t i = 1; i < security.size(); i++) {
            if (security[i] <= security[i - 1])
                prefix.push_back(prefix[i - 1] + 1);
            else
                prefix.push_back(1);
        }

        vector<int> suffix(security.size(), 1);
        for (int i = security.size() - 2; i > -1; i--) {
            if (security[i] <= security[i + 1])
                suffix[i] = suffix[i + 1] + 1;
        }

        vector<int> result;
        for (size_t i = 0; i < security.size(); i++) {
            if ((prefix[i] - 1) >= time && (suffix[i] - 1) >= time)
                result.push_back(i);
        }
        return result;
    }
};