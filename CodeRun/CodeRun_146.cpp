#include <iostream>
#include <deque>

using namespace std;

#pragma warning( disable : 4996) // for test

void firstWin(deque<int>& first, deque<int>& second) {
    first.push_back(first.front());
    first.pop_front();
    first.push_back(second.front());
    second.pop_front();
}
void secondWin(deque<int>& first, deque<int>& second) {
    second.push_back(first.front());
    first.pop_front();
    second.push_back(second.front());
    second.pop_front();
}

int main()
{
    freopen("input.txt", "r", stdin); // for test

    deque<int> first, second;

    int temp;
    for (size_t j = 0; j < 5; j++) {
        cin >> temp;
        first.push_back(temp);
    }
    for (size_t j = 0; j < 5; j++) {
        cin >> temp;
        second.push_back(temp);
    }

    int counter = 0;
    while (true) {
        if (first.empty() || second.empty())
            break;
        counter++;
        if (first.front() > second.front()) {
            if (first.front() == 9 && second.front() == 0) {
                secondWin(first, second);
                continue;
            }
            firstWin(first, second);
        }
        else {
            if (first.front() == 0 && second.front() == 9) {
                firstWin(first, second);
                continue;
            }
            secondWin(first, second);
        }
    }

    if (first.empty())
        cout << "second" << endl;
    else
        cout << "first" << endl;
    cout << counter << endl;
    return 0;
}