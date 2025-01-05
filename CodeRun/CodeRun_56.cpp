#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

#pragma warning( disable : 4996) // for test

int main()
{
	freopen("input.txt", "r", stdin); // for test

	size_t len;
	cin >> len;

	vector<int> arr;

	int temp;
	for (size_t i = 0; i < len * 2; i++)
	{
		cin >> temp;
		arr.push_back(temp);
	}

	set<pair<int, int>> turtleTree;
	for (size_t i = 0; i < arr.size(); i += 2)
	{
		if (arr[i] + arr[i + 1] == (arr.size() / 2) - 1 && arr[i] >= 0 && arr[i + 1] >= 0)
			turtleTree.insert(make_pair(arr[i], arr[i + 1]));
	}
	cout << turtleTree.size() << endl;

	return 0;
}