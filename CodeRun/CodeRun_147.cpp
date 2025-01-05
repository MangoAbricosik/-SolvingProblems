#include <iostream>
#include <string>
#include <vector>

using namespace std;

#pragma warning( disable : 4996) // for test

class MyQueue
{
public:
    void push_front(int value) {
        queue.emplace(queue.begin(), value);
        cout << "ok" << endl;
    }
    void push_back(int value) {
        queue.push_back(value);
        cout << "ok" << endl;
    }
    void pop_front() {
        if (queue.size() == 0) {
            cout << "error" << endl;
            return;
        }
        cout << queue.front() << endl;
        queue.erase(queue.begin());
    }
    void pop_back() {
        if (queue.size() == 0) {
            cout << "error" << endl;
            return;
        }
        cout << queue.back() << endl;
        queue.pop_back();
    }
    void front() {
        if (queue.size() == 0) {
            cout << "error" << endl;
            return;
        }
        cout << queue.front() << endl;
    }
    void back() {
        if (queue.size() == 0) {
            cout << "error" << endl;
            return;
        }
        cout << queue.back() << endl;
    }
    void size() {
        cout << queue.size() << endl;
    }
    void clear() {
        queue.erase(queue.begin(), queue.end());
        cout << "ok" << endl;
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
        if (temp == "push_front") {
            cin >> temp;
            que.push_front(stoi(temp));
        }
        else if (temp == "push_back") {
            cin >> temp;
            que.push_back(stoi(temp));
        }
        else if (temp == "pop_front") {
            que.pop_front();
        }
        else if (temp == "pop_back") {
            que.pop_back();
        }
        else if (temp == "front") {
            que.front();
        }
        else if (temp == "back") {
            que.back();
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