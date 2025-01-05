#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>;

using namespace std;

#pragma warning( disable : 4996) // for test

int main()
{
	freopen("input.txt", "r", stdin); // for test

	vector<int> bricks;
	vector<int> hole;
	for (int i = 0, temp; i < 3; ++i) {
		cin >> temp;
		bricks.push_back(temp);
	}
	for (int temp; cin >> temp; )
		hole.push_back(temp);


	int firstMin = *min_element(bricks.begin(), bricks.end());
	bricks.erase(min_element(bricks.begin(), bricks.end()));
	int secondMin = *min_element(bricks.begin(), bricks.end());
	bricks.erase(min_element(bricks.begin(), bricks.end()));

	if (firstMin <= hole[0] && secondMin <= hole[1])
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}