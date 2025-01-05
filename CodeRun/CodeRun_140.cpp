#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
using namespace std;

#pragma warning( disable : 4996) // for test

class MyStack
{
public:
	void push(int n);
	void pop();
	void back();
	void size();
	void clear();
	void exit();
private:
	bool stackIsEmpty(vector<int> arr);
	vector<int> arr;
};



int main()
{
	freopen("input.txt", "r", stdin); // for test

	MyStack myStack;
	string temp;
	while (true) {
		cin >> temp;
		if (temp == "push") {
			cin >> temp;
			myStack.push(stoi(temp));
		}
		else if (temp == "pop") {
			myStack.pop();
		}
		else if (temp == "back") {
			myStack.back();
		}
		else if (temp == "size") {
			myStack.size();
		}
		else if (temp == "clear") {
			myStack.clear();
		}
		else if (temp == "exit") {
			cout << "bye" << endl;
			break;
		}
	}

	return 0;
}

void MyStack::push(int n) {
	arr.push_back(n);
	cout << "ok" << endl;
}

void MyStack::pop() {
	if (!arr.empty()) {
		cout << arr.back() << endl;
		arr.pop_back();
	}
	else {
		cout << "error" << endl;
	}
}

void MyStack::back() {
	if (!arr.empty()) {
		cout << arr.back() << endl;
	}
	else {
		cout << "error" << endl;
	}
}

void MyStack::size() {
	cout << arr.size() << endl;
}

void MyStack::clear() {
	arr.erase(arr.begin(), arr.end());
	cout << "ok" << endl;
}

void MyStack::exit() {
	cout << "bye" << endl;
}

bool MyStack::stackIsEmpty(vector<int> arr) {
	if (arr.empty()) {
		return false;
	}
	return true;
}
