class Solution {
public:
    int minimumDeletions(string s) {
        vector<int> prefix;
        prefix.push_back(s[0] == 'b' ? 1 : 0);
        for (size_t i = 1; i < s.size(); i++) {
            prefix.push_back(prefix[i - 1] + (s[i] == 'b' ? 1 : 0));
        }

        vector<int> suffix(s.size() - 1);
        suffix.push_back(s[s.size() - 1] == 'a' ? 1 : 0);
        for (int i = s.size() - 2; i > -1; i--) {
            suffix[i] = suffix[i + 1] + (s[i] == 'a' ? 1 : 0);
        };

        int minDeletions = min(prefix[s.size() - 1], suffix[0]);
        for (size_t i = 0; i < s.size() - 1; i++) {
            int deletions = prefix[i] + suffix[i + 1];
            minDeletions = min(minDeletions, deletions);
        }
        return minDeletions;
    }
};