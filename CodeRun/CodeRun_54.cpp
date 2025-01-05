#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <sstream>
#include <map>

using namespace std;

#pragma warning( disable : 4996) // for test

// SOLVED

int main()
{
    freopen("input.txt", "r", stdin); // for test

    set<string> allKnow;
    map<string, int> repeat;

    int countOfPeople, countOfLanguage;
    cin >> countOfPeople;
    string temp;
    vector<vector<string>> base(countOfPeople);
    for (size_t i = 0; i < countOfPeople; i++) {
        cin >> countOfLanguage;
        base[i].resize(countOfLanguage);
        for (size_t j = 0; j < countOfLanguage; j++) {
            cin >> temp;
            base[i][j] = temp;
        }
    }

    for (auto item : base) {
        for (auto inner_item : item) {
            if (repeat.find(inner_item) == repeat.end()) {
                repeat.emplace(inner_item, 1);
            }
            else {
                repeat[inner_item]++;
            }
        }
    }

    vector<string> arr;
    int counter = 0;
    for (auto item : repeat) {
        if (item.second == countOfPeople) {
            counter++;
            arr.push_back(item.first);
        }
    }

    cout << counter << endl;
    for (auto item : arr)
        cout << item << endl;

    cout << repeat.size() << endl;
    for (auto item : repeat)
        cout << item.first << endl;
    return 0;
}

