#include <iostream>
#include <set>

using namespace std;

#pragma warning( disable : 4996) // for test

// SOLVED

int main()
{
    freopen("input.txt", "r", stdin); // for test

    int countOfAnnaCubes, countOfBoryaCobes;
    cin >> countOfAnnaCubes >> countOfBoryaCobes;

    set<int> annaCubes, boryaCubes, sharedCubes;
    for (size_t i = 0, temp; i < countOfAnnaCubes; i++) {
        cin >> temp;
        annaCubes.insert(temp);
    } // Получаем данные
    for (size_t i = 0, temp; i < countOfBoryaCobes; i++) {
        cin >> temp;
        boryaCubes.insert(temp);
    } // Получаем данные

    for (auto it = boryaCubes.begin(); it != boryaCubes.end();) {
        if (!annaCubes.insert(*it).second) {
            annaCubes.erase(*it);
            sharedCubes.insert(*it);
            boryaCubes.erase(*it);
            it = boryaCubes.begin();
        } // Если получилось вставить то удаляем элемент из дерева Ани и Бори, после вставляем в "общее" дерево
        else {
            annaCubes.erase(*it);
            ++it;
        } // Иначи удаляем новый элемент и инкрементируем итератор
    } // Перебираем все эелменты Бори, пытаясь вставитьв дерево Ани

    // Вывод данных
    cout << sharedCubes.size() << endl;
    for (auto item : sharedCubes)
        cout << item << endl;
    cout << annaCubes.size() << endl;
    for (auto item : annaCubes)
        cout << item << endl;
    cout << boryaCubes.size() << endl;
    for (auto item : boryaCubes)
        cout << item << endl;
    return 0;
}

