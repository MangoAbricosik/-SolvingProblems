#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <climits>
using namespace std;

#pragma warning( disable : 4996) // for test

int main()
{
	freopen("input.txt", "r", stdin); // for test

	char temp;
	map<char, int> arr;
	while (cin >> temp) {
		if (!arr.emplace(temp, 1).second) {
			arr[temp]++;
		}
	}

	int maxEl = INT_MIN;
	for (auto item : arr) {
		if (maxEl < item.second)
			maxEl = item.second;
	}

	for (size_t i = maxEl; i != 0; i--) {
		for (auto& item : arr) {
			if (item.second == i) {
				cout << "#";
				item.second--;
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}

	for (auto item : arr) {
		cout << item.first;
	}

	return 0;
}