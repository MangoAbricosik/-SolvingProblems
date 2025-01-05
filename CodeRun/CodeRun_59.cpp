#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>;

using namespace std;

#pragma warning( disable : 4996) // for test

int main()
{
    freopen("input.txt", "r", stdin); // for test

    set<string> words;
    for (std::string word; std::cin >> word; )
    {
        words.insert(word);
    }
    cout << words.size() << endl;

    return 0;
}

