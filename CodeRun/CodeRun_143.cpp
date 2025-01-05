#include <iostream>
#include <stack>

using namespace std;

#pragma warning( disable : 4996) // for test

int main()
{
	freopen("input.txt", "r", stdin); // for test

	stack<int> myStack;
	int temp, sizeOfTrain, currentNeed = 1;
	cin >> sizeOfTrain; // � �� ����������� ���
	bool symDone = false; // ������� ��������� = ���;

	do {
		if (cin >> temp)					// ���� ������ ���� ����� �� � ����
			myStack.push(temp);
		else								// ���� ������ ���������, ������� ����������
			symDone = true;

		while (!myStack.empty() && myStack.top() == currentNeed) { // ���� ���� �� ���� � �������� ��� �����
			myStack.pop();
			currentNeed++;
		}

		if (!myStack.empty() && symDone) {
			cout << "NO\n";
			return 0;
		}

	} while (!myStack.empty() || !symDone);				// ���� ��� �������� ���� ���������� �� �������� ����
	cout << "YES\n";						// � ������� �����, ��� "�����" ����� ������� � ���������� ����������������
	return 0;
}
