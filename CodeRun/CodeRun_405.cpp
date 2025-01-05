#include <iostream>
#include <vector>

using namespace std;

void tetramino_placement(vector<vector<char>>& two_dimensional_array)
{
	int counter = 0;
	int i = 0, j = 0;
	auto it = two_dimensional_array.at(i).begin() + j;
	while (i < 8)
	{
		while (j < 6)
		{
			it = two_dimensional_array.at(i).begin() + j;
			if (*it == '.' && *next(it) == '.' && *next(next(it)) == '.') // Гаризонтальное тетромино
			{
				if ((i < 7))
					if (*next(two_dimensional_array.at(i + 1).begin() + j) == '.')
						++counter;
				if (i > 0)
					if (*next(two_dimensional_array.at(i - 1).begin() + j) == '.')
						++counter;
			}
			++j;
		}
		++i; j = 0;
		if (!(i < 8))
			break;
	}
	i = 0, j = 0; // Сброс переменных
	while (i < 6)
	{
		while (j < 8)
		{

			vector<char>::iterator it1, it2, it3;

			it1 = two_dimensional_array.at(i).begin() + j; // Возможно ли это упростить??
			it2 = two_dimensional_array.at(i + 1).begin() + j;
			it3 = two_dimensional_array.at(i + 2).begin() + j;

			if (*it1 == '.' && *it2 == '.' && *it3 == '.') // Вертикальное тетромино
			{
				if (j < 7)
					if (*next(two_dimensional_array.at(i + 1).begin() + j) == '.')
						++counter;
				if (j > 0)
					if (*prev(two_dimensional_array.at(i + 1).begin() + j) == '.')
						++counter;
			}
			++j;
		}
		++i; j = 0;
		if (!(i < 6))
			break;
	}
	cout << counter << endl;
}


int main()
{
	vector<vector<char>> two_dimensional_array;
	char temp;
	for (size_t i = 0; i < 8; ++i) {
		vector<char> row;
		for (size_t j = 0; j < 8; ++j) {
			cin >> temp;
			row.push_back(temp); // Заполняем элементы вектора
		}
		two_dimensional_array.push_back(row); // Добавляем вектор в двухмерный массив
	}
	tetramino_placement(two_dimensional_array);
	return 0;
}