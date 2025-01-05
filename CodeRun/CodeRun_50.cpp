#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;

#pragma warning( disable : 4996) // for test

int main()
{
	freopen("input.txt", "r", stdin); // for test

	///////////////////////// // ������ ������
	string temp;
	string full;
	while (getline(cin, temp))
		full += temp + " ";
	while (full[0] == ' ') // ���� ����� ����������� � ' ', �� ������� ������ �������
		full.erase(full.begin(), full.begin() + 1);
	for (auto it = full.begin(); it != full.end() - 1;)
	{
		if (*it == ' ' && *next(it) == ' ') {
			full.erase(it);
		}
		else {
			++it;
		}
	}
	///////////////////////// //  ��������� �������
	temp = "";
	unordered_map<string, int> dictionary;
	for (size_t i = 0; i < full.size(); i++)
	{
		if (full[i] != ' ') // ���� ������ �� ������ �� ��������� � �����
			temp += full[i];
		else {
			auto familiar = dictionary.emplace(temp, 0);// �������� �� �� ���� �� ��� ����� � ������� // ���� ��� ��� ���� �� ������� false
			if (!familiar.second) // ���� ����� � ������� ���, �� ��������� ����� � �������
				dictionary[temp] += 1;
			temp = "";
		}
	}
	///////////////////////// // ������� ������������ ������ ����� ���� ����, �� ������� ����������� ����
	int max_index = 0;
	for (auto it = dictionary.begin(); it != dictionary.end(); ++it) // ������� � ���������� ����������� �������� � ����� ��������.
		if (max_index < it->second)
			max_index = it->second;
	///////////////////////// // ������� ��� �������� ���� ������������� �������
	for (auto it = cbegin(dictionary); it != cend(dictionary);) {
		auto& [word, count] = *it;
		if (count != max_index) {
			it = dictionary.erase(it);
		}
		else {
			++it;
		}
	}
	///////////////////////// // ������������ ��� ����� � �������� �������
	string min_word = dictionary.begin()->first;
	for (auto it = dictionary.begin(); it != dictionary.end();)
	{
		if (it->first < min_word) {
			min_word = it->first;
		}
		else {
			++it;
		}
	}
	cout << min_word << endl; // �����

	return 0;
}