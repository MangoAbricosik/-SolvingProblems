#include <iostream>
#include <string>
#include <vector>

using namespace std;

#pragma warning( disable : 4996) // for test

class MyQueue
{
public:
    void push(int value) {
        queue.push_back(value);
        cout << "ok" << endl;
    }
    void pop() {
        if (queue.size() == 0) {
            cout << "error" << endl;
            return;
        }
        cout << queue.front() << endl;
        queue.erase(queue.begin());
    }
    void front() {
        if (queue.size() == 0) {
            cout << "error" << endl;
            return;
        }
        cout << queue.front() << endl;
    }
    void size() {
        cout << queue.size() << endl;
    }
    void clear() {
        queue.erase(queue.begin(), queue.end());
        cout << "ok" << endl;;
    }

private:
    vector<int> queue;
};


int main()
{
    freopen("input.txt", "r", stdin); // for test

    MyQueue que;
    string temp;

    while (true) {
        cin >> temp;
        if (temp == "push") {
            cin >> temp;
            que.push(stoi(temp));
        }
        else if (temp == "pop") {
            que.pop();
        }
        else if (temp == "front") {
            que.front();
        }
        else if (temp == "size") {
            que.size();
        }
        else if (temp == "clear") {
            que.clear();
        }
        else if (temp == "exit") {
            cout << "bye" << endl;
            break;
        }
    }

    return 0;
}