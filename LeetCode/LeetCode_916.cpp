class Solution {
	bool had(map<char, int>& book, unordered_map<char, int>& dict) {
		for (auto& item : book) {
			if (dict[item.first] - item.second < 0)
				return false;
		}
		return true;
	}

public:
	vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
		map<char, int> book;
		for (auto& word : words2) {
			map<char, int> dict;
			for (auto& item : word)
				dict[item]++;
			for (auto& item : dict)
				book[item.first] = max(book[item.first], item.second);
		}
		vector<string> result;
		for (auto& word : words1) {
			unordered_map<char, int> dict;
			for (auto& item : word)
				dict[item]++;
			if (had(book, dict)) {
				result.push_back(word);
			}
		}
		return result;
	}