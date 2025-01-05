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

    set<int> tree; // ������ ��� ������ �����
    set<int> ans;  // ������ ��� �������� �����
    string temp;
    getline(cin, temp); // �������� ��� ������ ������
    istringstream iss(temp); // ����� ����� �� iss

    int test;
    while (iss >> test) // ��������� ������ ������ � ������
        tree.insert(test);
    while (cin >> test) {
        if (!tree.insert(test).second) { // ���� � ������� ������ ������ ��� ��� ����� �������
            ans.insert(test);            // �� �� ����� �������� � ������ ������
        }
    }
    for (auto item : ans) // ����� ������
        cout << item << endl;
    return 0;
}

