#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
#include <typeinfo>
#include <memory>
#include <vector>
#include <list>
#include <forward_list>
#include <algorithm>

using namespace std;
void FindAndDelete(vector<int>& arr, int value);
int CodeRun58()
{
	int temp; int extra = 0;

	vector<int> arr;
	while (extra < 3/*cin >> temp*/)
	{
		cin >> temp;
		arr.push_back(temp);
		extra++;
	}

	string current;
	cin >> current;
	vector<int> dribling;
	for (char item : current)
		dribling.push_back((int)item - 48);

	int unique_item = 0;

	for (vector<int>::iterator it = dribling.begin(); it != dribling.end(); ++it)
	{
		for (vector<int>::iterator inner_it = arr.begin(); inner_it != arr.end(); ++inner_it)
		{
			if (*it == *inner_it)
			{
				FindAndDelete(dribling, *inner_it);
				inner_it = arr.begin();
				it = dribling.begin();
				if (dribling.empty())
					goto final;
			}
		}
	}

	final:
	sort(dribling.begin(), dribling.end());
	auto it2 = std::unique(dribling.begin(), dribling.end());
	dribling.resize(distance(dribling.begin(), it2));
	return dribling.size();
}
void FindAndDelete(vector<int>& arr, int value)
{
	for (auto it = arr.begin(); it != arr.end(); it)
	{
		if (*it == value)
			it = arr.erase(it);
		else
			++it;
	}
}
int main()
{
	setlocale(LC_ALL, "ru");

	cout << CodeRun58() << endl;

	return 0;
}