#include <iostream>
#include <set>
using namespace std;

#pragma warning( disable : 4996) // for test

int main()
{
	freopen("input.txt", "r", stdin); // for test

	set<int> arr;
	int temp;
	while (cin >> temp && temp != 0)
		arr.insert(temp);
	for (auto item : arr)
		cout << item << endl;
	return 0;
}



