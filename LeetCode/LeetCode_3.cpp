class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mp;

        if (s.size() == 1)
            return 1;

        mp.emplace(s[0], 1);

        int r = 1, maxLength = 0;
        for (int l = 0; l < s.size(); l++) {
            while (r < s.size() && mp.emplace(s[r], 1).second) {
                if (mp.size() > maxLength)
                    maxLength = mp.size();
                r++;
            }

            mp.erase(mp.find(s[l]));
        }

        return maxLength;
    }
};