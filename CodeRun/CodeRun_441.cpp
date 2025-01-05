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
	////////////////////////////////// // Получение имен
	int howManyName;
	cin >> howManyName;
	map<string, int> nameVec;
	for (size_t i = 0; i < howManyName; i++) {
		string temp;
		cin >> temp;
		nameVec.emplace(temp, 0);
	};
	////////////////////////////////// // Получение изменений в счете
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
	////////////////////////////////// // Основа. Получаем счет. Вычисляем, кто забил. Начисляем очки
	int firstTeamCount = 0, secondTeamCount = 0;
	int prevFirstTeamCount = 0, prevSecondTeamCount = 0;
	int temp = 0;
	string nameOfStriker, TempCounter;
	for (size_t i = 0; i < changes; i++)
	{
		// От нулегового элемента до ':'
		for (size_t j = 0; j < find(counterVec[i].begin(), counterVec[i].end(), ':') - counterVec[i].begin(); j++)
			TempCounter += counterVec[i][j] + '0' - 48;
		firstTeamCount = stoi(TempCounter);
		TempCounter = "";

		// От ':' до ' '
		auto initial = ++find(counterVec[i].begin(), counterVec[i].end(), ':') - counterVec[i].begin();
		for (size_t j = initial; j < find(counterVec[i].begin(), counterVec[i].end(), ' ') - counterVec[i].begin(); j++)
			TempCounter += counterVec[i][j] + '0' - 48;
		secondTeamCount = stoi(TempCounter);

		// От ' ' до конца строки
		initial = ++find(counterVec[i].begin(), counterVec[i].end(), ' ') - counterVec[i].begin();
		for (size_t j = initial; j < counterVec[i].size(); j++)
			nameOfStriker += counterVec[i][j];

		// Какая команда забила гол?
		if (firstTeamCount > prevFirstTeamCount)
			temp = firstTeamCount - prevFirstTeamCount; // Прошлый счет - настоящий 
		else if (secondTeamCount > prevSecondTeamCount)
			temp = secondTeamCount - prevSecondTeamCount;

		nameVec[nameOfStriker] += temp; // Добовляем очки игкроку

		prevFirstTeamCount = firstTeamCount; // Обновляем "прошлый" счет
		prevSecondTeamCount = secondTeamCount;
		nameOfStriker = TempCounter = ""; // Чистим строки
	}

	int max_index = 0;
	string max_word = "";

	// Вычисляем максимальное имя с максимальным счетом
	for (auto& [word, count] : nameVec) {
		if (max_index <= count && max_word < word) {
			max_index = count;
			max_word = word;
		}
	}

	// Ответ
	cout << max_word << " " << max_index << endl;

	return 0;
}