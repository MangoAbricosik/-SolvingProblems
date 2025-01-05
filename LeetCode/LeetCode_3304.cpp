class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";

        for (size_t i = 0; i < k; i++) {
            if (word.size() >= k)
                break;
            auto temp = word;
            for (auto item : temp) {
                if (item >= 122)
                    item = 96;
                word += item + 1;
            }
        }

        return word[k - 1];
    }
};