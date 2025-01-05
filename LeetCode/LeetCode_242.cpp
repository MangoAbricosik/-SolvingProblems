class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> firstMp, secondMp;

        for (auto item : s)
            if (!firstMp.emplace(item, 1).second)
                firstMp[item]++;
        for (auto item : t)
            if (!secondMp.emplace(item, 1).second)
                secondMp[item]++;

        return firstMp == secondMp ? true : false;
    }
};