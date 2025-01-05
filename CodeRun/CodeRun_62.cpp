#include <iostream>
#include <set>

using namespace std;

#pragma warning( disable : 4996) // for test

// SOLVED

int main()
{
    freopen("input.txt", "r", stdin); // for test

    set<int> st;
    for (int temp; cin >> temp;)
        st.insert(temp);
    cout << st.size();
    return 0;
}

