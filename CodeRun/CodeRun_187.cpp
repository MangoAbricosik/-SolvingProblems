#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

#pragma warning( disable : 4996) // for test

int main()
{
	freopen("input.txt", "r", stdin); // for test

	int countOfTests, countOfCurrentTest;

	cin >> countOfTests;
	for (size_t i = 0; i < countOfTests; i++) {
		cin >> countOfCurrentTest;
		vector<int> arr(countOfCurrentTest);
		for (size_t j = 0; j < arr.size(); j++) {
			cin >> arr[j];
		}

		sort(arr.begin(), arr.end());
		int min = INT_MAX;
		for (auto it = arr.begin(); it != arr.end(); ++it) {
			if (next(it) != arr.end()) {
				if ((*it ^ *next(it)) < min) {
					min = *it ^ *next(it);
				}
			}
		}
		cout << min << endl;
	}

	return 0;
}
