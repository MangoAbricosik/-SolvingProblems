#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long Plus_Minus_Parsing(string& str)
{
	long long result = 0;
	string firstExpressionString, secondExpressionString;
	vector<long long> firstExpressionInt, secondExpressionInt;
	for (size_t i = 0; i < str.size(); ++i)
	{
		switch (str.at(i))
		{
		case '+':
			++i;
			while (true)
			{
				secondExpressionInt.push_back(str.at(i) - 48); // Заполняем второе число
				++i;
				if (!(i < str.size()) || str.at(i) == '+' || str.at(i) == '-')
					break;
			}
			for (auto item : firstExpressionInt) // Переносим int в string
				firstExpressionString += to_string(item);
			for (auto item : secondExpressionInt) // Переносим int в string
				secondExpressionString += to_string(item);
			if (firstExpressionInt.empty()) // Проверка на случай отсутвия первого элемента.
				result += stoi(secondExpressionString);
			else
				result += stoi(firstExpressionString) + stoi(secondExpressionString);

			firstExpressionInt.erase(firstExpressionInt.begin(), firstExpressionInt.end()); // Зачистка переменных
			secondExpressionInt.erase(secondExpressionInt.begin(), secondExpressionInt.end());
			firstExpressionString.erase(firstExpressionString.begin(), firstExpressionString.end());
			secondExpressionString.erase(secondExpressionString.begin(), secondExpressionString.end());
			--i;
			break;
		case '-':
			++i;
			while (true)
			{
				secondExpressionInt.push_back(str.at(i) - 48); // Заполняем второе число
				++i;
				if (!(i < str.size()) || str.at(i) == '+' || str.at(i) == '-')
					break;
			}
			for (auto item : firstExpressionInt) // Переносим int в string
				firstExpressionString += to_string(item);
			for (auto item : secondExpressionInt) // Переносим int в string
				secondExpressionString += to_string(item);
			if (firstExpressionInt.empty()) // Проверка на случай отсутвия первого элемента.
				result += -stoi(secondExpressionString);
			else
				result += stoi(firstExpressionString) - stoi(secondExpressionString);

			firstExpressionInt.erase(firstExpressionInt.begin(), firstExpressionInt.end()); // Зачистка переменных
			secondExpressionInt.erase(secondExpressionInt.begin(), secondExpressionInt.end());
			firstExpressionString.erase(firstExpressionString.begin(), firstExpressionString.end());
			secondExpressionString.erase(secondExpressionString.begin(), secondExpressionString.end());
			--i;
			break;
		default:
			firstExpressionInt.push_back(str.at(i) - 48); // Заполняем первое число
			break;
		}
	}
	if (secondExpressionInt.empty() && !firstExpressionInt.empty()) // Проверка на случай, если в строке не будет '+' или '-'
	{
		for (auto item : firstExpressionInt)
			firstExpressionString += to_string(item);
		return stoi(firstExpressionString);
	}
	return result;
}

int main()
{
	char temp;
	string str;
	while (cin >> temp)
	{
		str.push_back(temp);
	}
	cout << Plus_Minus_Parsing(str) << endl;

	return 0;
}