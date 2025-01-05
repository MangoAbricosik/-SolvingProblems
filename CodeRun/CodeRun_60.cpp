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
    } // �������� ������
    for (size_t i = 0, temp; i < countOfBoryaCobes; i++) {
        cin >> temp;
        boryaCubes.insert(temp);
    } // �������� ������

    for (auto it = boryaCubes.begin(); it != boryaCubes.end();) {
        if (!annaCubes.insert(*it).second) {
            annaCubes.erase(*it);
            sharedCubes.insert(*it);
            boryaCubes.erase(*it);
            it = boryaCubes.begin();
        } // ���� ���������� �������� �� ������� ������� �� ������ ��� � ����, ����� ��������� � "�����" ������
        else {
            annaCubes.erase(*it);
            ++it;
        } // ����� ������� ����� ������� � �������������� ��������
    } // ���������� ��� �������� ����, ������� ��������� ������ ���

    // ����� ������
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

