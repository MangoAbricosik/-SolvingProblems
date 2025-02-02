class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> result, temp;
        pair<int, int> borders;
        borders.first = 0;
        borders.second = s.size();

        for (auto item : s)
            temp.push_back(item);
        for (size_t i = 0; i < s.size() + 1; i++) {
            result.push_back(s[i] == 'I' ? borders.first++ : borders.second--);
        }

        return result;
    }
};