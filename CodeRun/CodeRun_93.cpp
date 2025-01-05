#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

#pragma warning( disable : 4996) // for test

int main()
{
	freopen("input.txt", "r", stdin); // for test

	int monuments, fog;
	cin >> monuments >> fog;
	vector<int> arr(monuments);
	for (auto& item : arr)
		cin >> item;

	int r = 0;
	long long result = 0;
	for (int l = 0; l < arr.size(); l++) {
		while (r < arr.size() && arr[r] - arr[l] <= fog)
			r++;
		result += arr.size() - r;
	}
	cout << result << endl;
	return 0;
}