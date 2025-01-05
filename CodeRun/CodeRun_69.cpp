#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int CodeRun69(vector<int>& arr)
{
	if (arr.size() < 3)
		return 0;
	auto it = arr.begin();
	int counter = 0;
	while (true)
	{
		++it;
		if (it == arr.end() - 1)
			break;
		if (*it > *prev(it) && *it > *next(it))
			counter++;
	}
	return counter;
}

int main()
{
	vector<int> arr;
	int temp;
	while (cin >> temp)
	{
		arr.push_back(temp);
	}
	cout << CodeRun69(arr) << endl;
	return 0;
}