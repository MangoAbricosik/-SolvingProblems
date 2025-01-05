#include <iostream>
#include <string>
#include <vector>

using namespace std;

#pragma warning( disable : 4996) // for test

void solved() {
	int vecSize;
	cin >> vecSize;

	vector<int> arr(vecSize);

	int temp;
	for (int i = 0; i < vecSize; i++) {
		cin >> temp;
		arr[i] = temp;
	}

	int currentInt;
	cin >> currentInt;

	int neerby = abs(arr[0] - currentInt);
	int min = arr[0];
	for (int i = 0; i < vecSize; i++) {
		if (arr[i] == currentInt) {
			cout << currentInt << endl;
			return;
		}

		if (abs(arr[i] - currentInt) < neerby) {
			neerby = abs(arr[i] - currentInt);
			min = arr[i];
		}
	}
	cout << min << endl;
	return;
}

int main() {
	freopen("input.txt", "r", stdin); // for test

	solved();

	return 0;
}