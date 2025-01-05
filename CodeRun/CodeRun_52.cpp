#include <iostream>
#include <string>
#include <vector>

using namespace std;

#pragma warning( disable : 4996) // for test

void solved() {
	int vecSize;
	cin >> vecSize;
	vector<pair<string, string>> arr(vecSize, pair<string, string>());

	string temp;
	for (int i = 0; i < vecSize; i++) {
		cin >> temp;
		arr[i].first = temp;
		cin >> temp;
		arr[i].second = temp;
	}

	string currentString;
	cin >> currentString;

	for (int i = 0; i < vecSize; i++) {
		if (arr[i].first == currentString) {
			cout << arr[i].second << endl;
			return;
		}
		if (arr[i].second == currentString) {
			cout << arr[i].first << endl;
			return;
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin); // for test

	solved();

	return 0;
}