class Solution {
public:
    int minimumPushes(string word) {
        vector<int> vec(26, 0);
        for (char item : word)
            vec[item - 'a']++;
        sort(vec.begin(), vec.end());
        int result = 0, sz = 25;
        for (; sz >= 0 && vec[sz] != 0; sz--) {
            result += vec[sz] * ((25 - sz) / 8 + 1);
        }

        return result;
    }
};