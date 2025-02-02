class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char, int> dict;
        for (auto item : s)
            dict[item]++;
        for (auto item : t) {
            dict[item]--;
            if (dict[item] == -1)
                return item;
        }
        return 'A';
    }
};