#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;

#pragma warning( disable : 4996) // for test



int main()
{
	freopen("input.txt", "r", stdin); // for test

	int size, count = 0;
	cin >> size;

	vector<int> arr(size);
	if (size > 0) {
		arr[0] = 1;
	}
	if (size > 1) {
		arr[1] = 1;
	}
	for (size_t i = 2; i < size; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}

	cout << accumulate(arr.begin(), arr.end(), 0, plus<int>()) << endl;

	return 0;
}