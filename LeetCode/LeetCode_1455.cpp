class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        istringstream iss(sentence);
        vector<string> dict;
        string temp;
        while (iss >> temp) {
            dict.push_back(temp);
        }

        for (size_t i = 0; i < dict.size(); i++) {
            if (searchWord.size() <= dict[i].size() && searchWord == dict[i].substr(0, searchWord.size()))
                return i + 1;
        }
        return -1;
    }
};