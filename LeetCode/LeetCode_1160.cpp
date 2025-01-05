class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        map<char, int> charsMp;
        for (size_t i = 0; i < chars.size(); i++) {
            if (!charsMp.emplace(chars[i], 1).second)
                charsMp[chars[i]]++;
        }

        int result = 0;
        bool isBad = false;
        for (size_t i = 0; i < words.size(); i++) {
            map<char, int> tempMp = charsMp;
            for (size_t j = 0; j < words[i].size(); j++) {
                if (tempMp.find(words[i][j]) != tempMp.end()) {
                    tempMp[words[i][j]]--;
                }
                else
                    goto next;
            }
            for (auto item : tempMp) {
                if (item.second < 0)
                    isBad = true;
            }
            if (!isBad)
                result += words[i].size();
        next:
            isBad = false;
        }

        return result;
    }
};