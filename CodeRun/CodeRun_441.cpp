#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#pragma warning( disable : 4996) // for test

// SOLVED

int main()
{
	freopen("input.txt", "r", stdin); // for test
	////////////////////////////////// // ��������� ����
	int howManyName;
	cin >> howManyName;
	map<string, int> nameVec;
	for (size_t i = 0; i < howManyName; i++) {
		string temp;
		cin >> temp;
		nameVec.emplace(temp, 0);
	};
	////////////////////////////////// // ��������� ��������� � �����
	int changes;
	cin >> changes;
	vector<string> counterVec;
	for (size_t i = 0; i < changes + 1; i++)
	{
		string temp = "";
		getline(cin, temp);
		counterVec.push_back(temp);
	}
	counterVec.erase(counterVec.begin());
	////////////////////////////////// // ������. �������� ����. ���������, ��� �����. ��������� ����
	int firstTeamCount = 0, secondTeamCount = 0;
	int prevFirstTeamCount = 0, prevSecondTeamCount = 0;
	int temp = 0;
	string nameOfStriker, TempCounter;
	for (size_t i = 0; i < changes; i++)
	{
		// �� ���������� �������� �� ':'
		for (size_t j = 0; j < find(counterVec[i].begin(), counterVec[i].end(), ':') - counterVec[i].begin(); j++)
			TempCounter += counterVec[i][j] + '0' - 48;
		firstTeamCount = stoi(TempCounter);
		TempCounter = "";

		// �� ':' �� ' '
		auto initial = ++find(counterVec[i].begin(), counterVec[i].end(), ':') - counterVec[i].begin();
		for (size_t j = initial; j < find(counterVec[i].begin(), counterVec[i].end(), ' ') - counterVec[i].begin(); j++)
			TempCounter += counterVec[i][j] + '0' - 48;
		secondTeamCount = stoi(TempCounter);

		// �� ' ' �� ����� ������
		initial = ++find(counterVec[i].begin(), counterVec[i].end(), ' ') - counterVec[i].begin();
		for (size_t j = initial; j < counterVec[i].size(); j++)
			nameOfStriker += counterVec[i][j];

		// ����� ������� ������ ���?
		if (firstTeamCount > prevFirstTeamCount)
			temp = firstTeamCount - prevFirstTeamCount; // ������� ���� - ��������� 
		else if (secondTeamCount > prevSecondTeamCount)
			temp = secondTeamCount - prevSecondTeamCount;

		nameVec[nameOfStriker] += temp; // ��������� ���� �������

		prevFirstTeamCount = firstTeamCount; // ��������� "�������" ����
		prevSecondTeamCount = secondTeamCount;
		nameOfStriker = TempCounter = ""; // ������ ������
	}

	int max_index = 0;
	string max_word = "";

	// ��������� ������������ ��� � ������������ ������
	for (auto& [word, count] : nameVec) {
		if (max_index <= count && max_word < word) {
			max_index = count;
			max_word = word;
		}
	}

	// �����
	cout << max_word << " " << max_index << endl;

	return 0;
}