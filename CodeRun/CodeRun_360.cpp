#include <iostream>
#include <map>
#include <algorithm>
#include <climits>
using namespace std;

#pragma warning( disable : 4996) // for test

int main()
{
	freopen("input.txt", "r", stdin); // for test

	int temp, size;
	cin >> size;
	map<int, int> arr;
	while (cin >> temp) {
		if (!arr.emplace(temp, 1).second) {
			arr[temp]++;
		}
	}

	auto result = arr.begin();
	int max_value = INT_MIN;
	int max_counter = INT_MIN;
	for (auto it = arr.begin(); it != arr.end(); ++it) {
		if (max_counter < it->second) {
			max_counter = it->second;
		}
	}
	for (auto it = arr.begin(); it != arr.end(); ++it) {
		if (max_counter == it->second) {
			if (max_value < it->first) {
				max_value = it->first;
				result = it;
			}
		}
	}

	cout << result->first << endl;

	return 0;
}
