class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        map<char, int> main;
        for (auto item : p)
            main[item]++;

        map<char, int> window;
        for (size_t i = 0; i < p.size(); i++) {
            window[s[i]]++;
        }

        vector<int> result;
        if (window == main)
            result.push_back(0);

        for (size_t i = p.size(); i < s.size(); i++) {
            window[s[i]]++;
            window[s[i - p.size()]]--;
            if (window[s[i - p.size()]] == 0)
                window.erase(s[i - p.size()]);

            if (window == main)
                result.push_back(i - (p.size() - 1));
        }

        return result;
    }
};