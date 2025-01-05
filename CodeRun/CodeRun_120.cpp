#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

#pragma warning( disable : 4996) // for test

typedef struct tree_element {
	int counterOfDeep;
	int value;
	struct tree_element* left;
	struct tree_element* right;
} tree_element;

tree_element* create_tree_element(int i);

void insert_into_tree(tree_element* root, tree_element* elem);

void getTreeDeep(tree_element* cur_elem, vector<int>& arr);



int main()
{
	freopen("input.txt", "r", stdin); // for test

	int temp;
	set<int> mySet;
	vector<int> arr;
	while (cin >> temp) {
		if (temp == 0)
			break;
		else if (mySet.insert(temp).second) {
			arr.push_back(temp);
			mySet.insert(temp);
		}
	}

	tree_element* root = create_tree_element(*arr.begin());
	arr.erase(arr.begin());
	for (auto item : arr) {
		tree_element* el = create_tree_element(item);
		insert_into_tree(root, el);
	}

	arr.clear();
	getTreeDeep(root, arr);
	cout << ++ * max_element(arr.begin(), arr.end()) << endl;
	return 0;
}

tree_element* create_tree_element(int i) {
	tree_element* elem = new tree_element;
	elem->counterOfDeep = 0;
	elem->value = i;
	elem->left = NULL;
	elem->right = NULL;
	return elem;
}

void insert_into_tree(tree_element* root, tree_element* elem) {
	if (elem->value < root->value) {
		if (root->left == NULL) {
			root->left = elem;
			elem->counterOfDeep = root->counterOfDeep + 1;
		}
		else {
			insert_into_tree(root->left, elem);
		}
	}
	else {
		if (root->right == NULL) {
			root->right = elem;
			elem->counterOfDeep = root->counterOfDeep + 1;
		}
		else {
			insert_into_tree(root->right, elem);
		}
	}
}

void getTreeDeep(tree_element* cur_elem, vector<int>& arr) {
	if (cur_elem->left != NULL) {
		getTreeDeep(cur_elem->left, arr);
	}
	arr.push_back(cur_elem->counterOfDeep);
	if (cur_elem->right != NULL) {
		getTreeDeep(cur_elem->right, arr);
	}
}


