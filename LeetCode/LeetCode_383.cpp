class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> magazineMp;
        for (size_t i = 0; i < magazine.size(); i++) {
            if (!magazineMp.emplace(magazine[i], 1).second)
                magazineMp[magazine[i]]++;
        }

        map<char, int> ransomNoteMp;
        for (size_t i = 0; i < ransomNote.size(); i++) {
            if (!ransomNoteMp.emplace(ransomNote[i], 1).second)
                ransomNoteMp[ransomNote[i]]++;
        }

        for (size_t i = 0; i < ransomNote.size(); i++) {
            if (ransomNoteMp.find(ransomNote[i]) != ransomNoteMp.end() && magazineMp.find(ransomNote[i]) != magazineMp.end()
                && ransomNoteMp[ransomNote[i]] > 0 && magazineMp[ransomNote[i]] > 0) {
                ransomNoteMp[ransomNote[i]]--;
                magazineMp[ransomNote[i]]--;
            }
            else
                return false;
        }
        return true;
    }
};