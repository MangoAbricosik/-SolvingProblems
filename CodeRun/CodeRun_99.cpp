#include <iostream>
#include <vector>

using namespace std;

#pragma warning( disable : 4996) // for test

string binSearch(vector<int>& arr, int targetValue) {
    if (arr.empty()) // ���� ������ ������ - ������� "NO"
        return "NO";

    int l = 0, r = arr.size() - 1; // ����� � ������ �������
    while (l <= r) {
        int m = (l + r) / 2;

        if (arr[m] == targetValue) // ���� ����� ������� "YES"
            return "YES";

        if (arr[m] < targetValue) // ���������� ����� ������
            l = m + 1; // ��������� m � ��� ��� �����
        else
            r = m - 1; // ��������� m � ��� ��� ������
    } // ��������� ���� ������� �� ����� ���� �� �����

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
    } // ��������� ������
    for (size_t i = 0, temp; i < secondSize; i++) {
        cin >> temp;
        secondVec.push_back(temp);
    } // ��������� ������

    for (auto item : secondVec) {
        cout << binSearch(firstVec, item) << endl;
    } // ����� ������� ��������� ������

    return 0;
}

