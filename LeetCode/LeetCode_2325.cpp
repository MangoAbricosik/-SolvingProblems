class Solution {
public:
	string decodeMessage(string key, string message) {
		unordered_map<char, char> dict;
		char tmp = 'a';
		for (auto item : key)
			if (item != ' ' && dict.find(item) == dict.end())
				dict[item] = tmp++;

		for (auto& item : message)
			item = item == ' ' ? ' ' : dict[item];
		return message;
	}
};