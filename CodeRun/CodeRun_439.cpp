#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

#pragma warning( disable : 4996) // for test

int main()
{
	freopen("input.txt", "r", stdin); // for test

	string str;
	string temp;
	while (getline(cin, temp))
		str += temp;

	map<string, int> dictionary;
	temp = "";
	for (auto it = str.begin(); it < str.end() - 1; ++it) // «аполн€ем дерево
	{
		if (*it != ' ' && *next(it) != ' ')
		{
			temp = *it;
			temp += *next(it);
			auto familiar = dictionary.emplace(temp, 0);
			if (!familiar.second)
				++dictionary[temp];
		}
	}

	int max_index = 0;
	string max_word = "";

	for (auto& [word, count] : dictionary) {
		if (max_index <= count && max_word < word) {
			max_index = count;
			max_word = word;
		}
	}

	cout << max_word << endl;
	// Ќайти макс значение в векторе и убрать все остальные значени€ и соответсувующие из st. ƒалее сравнить st на основе данных из arr

	return 0;
}

