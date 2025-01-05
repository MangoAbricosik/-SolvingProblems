#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int Genomic_counter(multiset<pair<char, char>>& st1, set<pair<char, char>>& st2)
{
	int counter = 0;
	for (auto item : st1)
	{
		for (auto inner_item : st2)
		{
			if (item.first == inner_item.first && item.second == inner_item.second)
				counter++;
		}
	}
	return counter;
}
int main()
{
	setlocale(LC_ALL, "en_US");

	multiset<pair<char, char>> st1;
	set<pair<char, char>> st2;

	string test1;
	string test2;

	cin >> test1;
	cin >> test2;

	string temp;
	for (auto it = test1.begin(); it < test1.end() - 1; ++it)
		st1.insert(pair<char, char>(*it, *next(it)));
	for (auto it = test2.begin(); it < test2.end() - 1; ++it)
		st2.insert(pair<char, char>(*it, *next(it)));

	cout << Genomic_counter(st1, st2) << endl;

	return 0;
}
