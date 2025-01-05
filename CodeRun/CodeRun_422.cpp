#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>;

using namespace std;

#pragma warning( disable : 4996) // for test

// SOLVED

int main()
{
    freopen("input.txt", "r", stdin); // for test

    int count;
    cin >> count;

    vector<string> arr(count);
    vector<set<string>> tree(count);
    vector<int> secsec(count);
    string temp; bool bobobo = true;
    for (int i = 0; cin >> temp; ++i)
        arr[i] = temp;

    for (size_t i = 0; i < count; i++) {
        bobobo = true;
        tree[i].insert(arr[i]);
        for (auto item : arr) {
            for (auto inner_item : item) {
                for (auto inner_tree_item : tree[i]) {
                    for (auto inner_inner_tree_item : inner_tree_item) {
                        if (inner_inner_tree_item == inner_item) {
                            tree[i].insert(item);
                            if (!tree[i].insert(item).second && bobobo) {
                                secsec[i] += 1;
                                bobobo = false;
                            }
                        }
                    }
                }
            }
        }
    }

    int max_index = -1, max_second_index = -1;; int i = 0;
    for (auto item : tree) {
        int test = item.size();
        if (test > max_index)
            max_index = item.size();
        max_second_index = secsec[i];
        i++;
    }

    cout << max_index + max_second_index << endl;

    return 0;
}