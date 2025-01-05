#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <sstream>
using namespace std;

#pragma warning( disable : 4996) // for test

// SOLVED

int main()
{
    freopen("input.txt", "r", stdin); // for test

    set<int> tree; // Дерево для поиска копий
    set<int> ans;  // Дерево для хранения копий
    string temp;
    getline(cin, temp); // Получаем всю первую строку
    istringstream iss(temp); // Поток ввода на iss

    int test;
    while (iss >> test) // Заполняем первую строку в дерево
        tree.insert(test);
    while (cin >> test) {
        if (!tree.insert(test).second) { // Если в символе второй строки уже был такой элемент
            ans.insert(test);            // То он будет добавлен в дерево ответа
        }
    }
    for (auto item : ans) // Вывод ответа
        cout << item << endl;
    return 0;
}

