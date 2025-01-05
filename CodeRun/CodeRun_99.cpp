#include <iostream>
#include <vector>

using namespace std;

#pragma warning( disable : 4996) // for test

string binSearch(vector<int>& arr, int targetValue) {
    if (arr.empty()) // Если пустой массив - вывести "NO"
        return "NO";

    int l = 0, r = arr.size() - 1; // Левая и правая границы
    while (l <= r) {
        int m = (l + r) / 2;

        if (arr[m] == targetValue) // Если нашли вывести "YES"
            return "YES";

        if (arr[m] < targetValue) // Присвоение новых границ
            l = m + 1; // Отсеиваем m и все что левее
        else
            r = m - 1; // Отсеиваем m и все что правее
    } // Выполнять пока границы не зашли друг за друга

    return "NO";
}

int main()
{
    freopen("input.txt", "r", stdin); // for test

    int firstSize, secondSize;
    cin >> firstSize >> secondSize;

    vector<int> firstVec, secondVec;
    for (size_t i = 0, temp; i < firstSize; i++) {
        cin >> temp;
        firstVec.push_back(temp);
    } // Получение данных
    for (size_t i = 0, temp; i < secondSize; i++) {
        cin >> temp;
        secondVec.push_back(temp);
    } // Получение данных

    for (auto item : secondVec) {
        cout << binSearch(firstVec, item) << endl;
    } // Вызов функции бинарного поиска

    return 0;
}

