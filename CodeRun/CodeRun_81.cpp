#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	vector<int> arr;
	int temp;
	while (cin >> temp)
		arr.push_back(temp);
	auto max = *max_element(arr.begin(), arr.end());
	remove(arr.begin(), arr.end(), max);
	if (*min_element(arr.begin(), arr.end()) == 0)
		cout << "NO" << endl;
	if (max < arr.at(0) + arr.at(1))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}