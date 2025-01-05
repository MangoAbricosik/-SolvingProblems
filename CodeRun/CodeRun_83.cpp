#include <iostream>
#include <vector>

using namespace std;

#pragma warning( disable : 4996) // for test

int main()
{
	freopen("input.txt", "r", stdin); // for test

	int countOfKeys, countOfCicks, temp;
	cin >> countOfKeys;
	vector<int> keys(countOfKeys);
	for (auto& item : keys)
		cin >> item;
	cin >> countOfCicks;
	for (size_t i = 0; i < countOfCicks; i++) {
		cin >> temp;
		--temp;
		keys[temp]--;
	}

	for (const auto item : keys) {
		if (item < 0)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}
