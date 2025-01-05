#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

#pragma warning( disable : 4996) // for test

int main()
{
    freopen("input.txt", "r", stdin); // for test

    int size, temp, counter = 0;
    cin >> size;

    map<int, int> arr;

    for (size_t i = 0; i < size; i++) {
        cin >> temp;
        if (!arr.emplace(temp, 1).second) {
            arr[temp]++;
        }
    }


    for (auto [first, second] : arr) {
        if (second == 1) {
            counter++;
        }
    }

    cout << counter << endl;

    return 0;
}