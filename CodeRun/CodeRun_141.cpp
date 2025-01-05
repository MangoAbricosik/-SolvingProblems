#include <iostream>
#include <stack>

using namespace std;

#pragma warning( disable : 4996) // for test

char openingBracket(char closinBracket) {
	if (closinBracket == ')')
		return '(';
	else if (closinBracket == ']')
		return '[';
	else if (closinBracket == '}')
		return '{';
}

int main()
{
	freopen("input.txt", "r", stdin); // for test

	stack<char> opened;
	string sequnce;
	cin >> sequnce;

	for (char c : sequnce) {
		if (c == '(' || c == '[' || c == '{') {
			opened.push(c);
		}
		else if (!opened.empty() && opened.top() == openingBracket(c)) {
			opened.pop();
		}
		else {
			cout << "no\n";
			return 0;
		}
	}

	if (opened.empty()) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}

	return 0;
}
