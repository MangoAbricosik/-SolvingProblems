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

	///////////////////////// // Читаем данные
	string temp;
	string full;
	while (getline(cin, temp))
		full += temp + " ";
	while (full[0] == ' ') // Если слово начинаеться с ' ', то удалить первый элемент
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
	///////////////////////// //  Заполняем словарь
	temp = "";
	unordered_map<string, int> dictionary;
	for (size_t i = 0; i < full.size(); i++)
	{
		if (full[i] != ' ') // Если символ не пробел то добовляем в слово
			temp += full[i];
		else {
			auto familiar = dictionary.emplace(temp, 0);// Проверка на то есть ли это слово в словаре // Если оно уже есть то получим false
			if (!familiar.second) // Если слова в словаре нет, то добовляем слово в словарь
				dictionary[temp] += 1;
			temp = "";
		}
	}
	///////////////////////// // Находим максимальный индекс среди всех слов, то которое встречалось чаще
	int max_index = 0;
	for (auto it = dictionary.begin(); it != dictionary.end(); ++it) // Вариант с предикатом получаеться огромным и менее читаемым.
		if (max_index < it->second)
			max_index = it->second;
	///////////////////////// // Удаляем все элементы ниже максимального индекса
	for (auto it = cbegin(dictionary); it != cend(dictionary);) {
		auto& [word, count] = *it;
		if (count != max_index) {
			it = dictionary.erase(it);
		}
		else {
			++it;
		}
	}
	///////////////////////// // Сравнимаваем все слова и выбираем меньшее
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
	cout << min_word << endl; // Вывод

	return 0;
}