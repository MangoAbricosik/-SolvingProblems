#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

#pragma warning( disable : 4996) // for test

int main()
{
	freopen("input.txt", "r", stdin); // for test

	int elementsCount, favoriteNubmer;
	cin >> elementsCount >> favoriteNubmer;
	vector<int> arr(elementsCount);
	for (auto& item : arr)
		cin >> item;
	int r = 0, temp = 0, result = 0;;
	for (size_t l = 0; l < arr.size() || r < arr.size();) {
		if (l == r || l > r) {
			temp = arr[l];
			r = l;
		}

		if (temp < favoriteNubmer) {
			r++;
			if (l < arr.size() && r < arr.size())
				temp += arr[r];
			else
				break;
		}
		else if (temp > favoriteNubmer) {
			temp -= arr[l];
			l++;
		}
		else if (temp == favoriteNubmer) {
			temp -= arr[l];
			l++;
			result++;
		}
	}
	cout << result << endl;



	return 0;
}