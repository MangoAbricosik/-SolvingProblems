#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#pragma warning( disable : 4996) // for test

class Tree
{
public:

	Tree() { size = 0; }

	vector<pair<string, int>> countingLevels() {
		return countingLevels(root);
	}

	void NumberOfDescendants() {
		return NumberOfDescendants(root);
	}

	bool insert(string parent, string children) {
		return insert(root, parent, children);
	}

	bool contains(string name) {
		return contains(root, name);
	}
private:
	int size;

	struct Node {
		string name;
		vector<Node*> childrens;

		Node(string name) {
			this->name = name;
		}
	} *root = nullptr;

	bool contains(Node* n, string name, int i = 0) {
		if (name == n->name)
			return true;
		for (auto item : n->childrens) {
			contains(item, name, i);
		}
		return false;
	};

	bool insert(Node* n, string parent, string children) {

		if (!root) {
			root = new Node(parent);
			Node* temp = new Node(children);
			root->childrens.push_back(temp);
			size++;
			return true;
		}
		if (n->name == parent) {
			Node* temp = new Node(children);
			n->childrens.push_back(temp);
			size++;
			return true;
		}
		for (auto item : n->childrens) {
			insert(item, parent, children);
		}

		return false;
	}

	void NumberOfDescendants(Node* n) {
		cout << n->name << " " << n->childrens.size() << endl;
		for (auto item : n->childrens) {
			NumberOfDescendants(item);
		}
	}

	vector<pair<string, int>> temp;
	vector<pair<string, int>> countingLevels(Node* n, int i = 0) {
		temp.push_back({ n->name, i });
		for (auto item : n->childrens) {
			countingLevels(item, i + 1);
		}
		return temp;
	}
};


int main() {
	freopen("input.txt", "r", stdin); // for test

	int count;
	cin >> count;

	Tree tr;
	vector<pair<string, string>> dict;
	for (size_t i = 0; i < (count - 1); i++) {
		string child, parent;
		cin >> child >> parent;
		dict.push_back({ child, parent });
	}

	queue<string> qe;
	pair<string, string> strQQ;
	bool yesWeHave = true;
	for (size_t i = 0;; i++) {
		strQQ = dict[i];
		for (auto item : dict) {
			if (item.first == strQQ.second)
				yesWeHave = false;
		}
		if (yesWeHave)
			break;
		yesWeHave = true;
	}

	vector<pair<string, string>> result;
	qe.push(strQQ.second);
	for (size_t i = 0; result.size() != dict.size() || i < dict.size(); i++) {
		if (i == dict.size()) {
			i = 0;
			qe.pop();
		}
		if (qe.front() == dict[i].second) {
			qe.push(dict[i].first);
			result.push_back({ dict[i].first, dict[i].second });
		}
	}

	for (auto [child, parent] : result) {
		tr.insert(parent, child);
	}

	auto temp = tr.countingLevels();
	sort(temp.begin(), temp.end());
	for (auto [str, val] : temp)
		cout << str << " " << val << endl;

	return 0;
}
