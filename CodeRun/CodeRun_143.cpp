#include <iostream>
#include <stack>

using namespace std;

#pragma warning( disable : 4996) // for test

int main()
{
	freopen("input.txt", "r", stdin); // for test

	stack<int> myStack;
	int temp, sizeOfTrain, currentNeed = 1;
	cin >> sizeOfTrain; // Я не использовал это
	bool symDone = false; // Символы кончились = нет;

	do {
		if (cin >> temp)					// Пока номера есть кидаю их в стек
			myStack.push(temp);
		else								// Если номера кончились, помечаю переменную
			symDone = true;

		while (!myStack.empty() && myStack.top() == currentNeed) { // Если стэк не пуст и подходит под число
			myStack.pop();
			currentNeed++;
		}

		if (!myStack.empty() && symDone) {
			cout << "NO\n";
			return 0;
		}

	} while (!myStack.empty() || !symDone);				// Если все элементы были обработаны то звершаем цикл
	cout << "YES\n";						// И выводим ответ, что "поезд" можно собрать в правильной последовательсти
	return 0;
}
