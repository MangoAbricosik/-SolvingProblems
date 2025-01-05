#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#pragma warning( disable : 4996) // for test

int main()
{

	freopen("input.txt", "r", stdin); // for test

	int size;
	cin >> size;

	vector<int> arr(size);
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}

	make_heap(arr.begin(), arr.end());
	sort_heap(arr.begin(), arr.end());

	for (int i = 0; i < size; i++) {
		cout << arr[i] << endl;
	}
	return 0;
}