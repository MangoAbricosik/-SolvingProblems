class Solution {
public:
    string sortSentence(string s) {
        map<int, string> dict;
        istringstream stream(s);
        string temp;
        while (stream >> temp) {
            dict[temp[temp.size() - 1]] = temp.substr(0, temp.size() - 1);
        }

        string result = "";
        for (auto item : dict) {
            result += item.second + " ";
        }

        return result.substr(0, result.size() - 1);
    }
};