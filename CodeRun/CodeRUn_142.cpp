#include <iostream>
#include <stack>

using namespace std;

#pragma warning( disable : 4996) // for test

void getVaribles(int& first, int& second, stack<int>& opened) {
	first = opened.top();
	opened.pop();

	second = opened.top();
	opened.pop();
}

int main()
{
	freopen("input.txt", "r", stdin); // for test

	stack<int> opened;
	char temp;
	int  first, second;

	while (cin >> temp) {
		if (isdigit(temp)) {
			opened.push(temp - 48);
		}
		else {
			getVaribles(first, second, opened);
			if (temp == '+')
				opened.push(first + second);
			else if (temp == '-')
				opened.push(second - first);
			else if (temp == '*')
				opened.push(first * second);
		}
	}

	cout << opened.top();

	return 0;
}
