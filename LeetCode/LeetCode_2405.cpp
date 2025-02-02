class Solution {
public:
    int partitionString(string s) {
        int result = 0;
        unordered_map<char, int> mp;
        for (size_t i = 0; i < s.size(); i++) {
            if (mp[s[i]] > 0) {
                result++;
                mp.clear();
            }
            mp[s[i]]++;
        }
        if (!mp.empty())
            result++;
        return result;
    }
};