#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

#pragma warning( disable : 4996) // for test

int main()
{
    freopen("input.txt", "r", stdin); // for test
    int trash;
    cin >> trash;
    deque<int> que;
    string temp;
    while (cin >> temp) {
        if (temp == "+") {
            cin >> temp;
            que.push_back(stoi(temp));
        }
        else if (temp == "*") {
            cin >> temp;
            if (que.size() % 2 == 0) {
                auto it = que.begin();
                que.emplace(it + que.size() / 2, stoi(temp));
            }
            else {
                auto it = que.begin();
                que.emplace(it + que.size() / 2 + 1, stoi(temp));
            }
        }
        else if (temp == "-") {
            cout << que.front() << endl;
            que.pop_front();
        }
    }
    return 0;
}