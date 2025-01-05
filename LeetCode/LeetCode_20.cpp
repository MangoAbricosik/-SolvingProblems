class Solution {
public:
	char openingBracket(char closinBracket) {
		if (closinBracket == ')')
			return '(';
		else if (closinBracket == ']')
			return '[';
		else if (closinBracket == '}')
			return '{';
		return '(';
	}

	bool isValid(std::string s) {
		std::stack<char> opened;
		for (char c : s) {
			if (c == '(' || c == '[' || c == '{') {
				opened.push(c);
			}
			else if (!opened.empty() && opened.top() == openingBracket(c)) {
				opened.pop();
			}
			else {
				return false;
			}
		}

		if (opened.empty()) {
			return true;
		}
		return false;
	}
};