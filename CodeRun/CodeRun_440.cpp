#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#pragma warning( disable : 4996) // for test

// SOLVED

int main()
{
	freopen("input.txt", "r", stdin); // for test

	vector<int> arr;
	for (int temp; cin >> temp;)
		arr.push_back(temp);

	int counter = 4, in_total = 0;
	bool overflow = false;
	for (auto item : arr) {
		if (in_total + *min_element(arr.begin(), arr.end()) <= 4) {
			in_total += *min_element(arr.begin(), arr.end());
			arr.erase(min_element(arr.begin(), arr.end()));
			counter--;
		}
		else
			overflow = true;
	}
	if (overflow)
		cout << counter << endl;
	else if (in_total == 4)
		cout << 0 << endl;
	else if (!overflow && in_total == 3)
		cout << 0 << endl;
	else if (!overflow && in_total == 2)
		cout << 0 << endl;
	else if (!overflow && in_total < 2)
		cout << 1 << endl;

	return 0;
}