class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<map<char, int>> arr;
        vector<vector<string>> result;
        bool insertDone = false;

        map<char, int> temp;
        for (size_t i = 0; i < strs.size(); i++) {
            temp.clear();
            for (size_t j = 0; j < strs[i].size(); j++) {
                if (!temp.emplace(strs[i][j], 1).second)
                    temp[strs[i][j]]++;
            }
            for (size_t j = 0; j < arr.size(); j++) {
                if (arr[j] == temp) {
                    result[j].push_back(strs[i]);
                    insertDone = true;
                }
            }
            if (!insertDone) {
                arr.push_back(temp);
                vector<string> strTemp{ strs[i] };
                result.push_back(strTemp);
            }
            insertDone = false;
        }
        return result;
    }
};