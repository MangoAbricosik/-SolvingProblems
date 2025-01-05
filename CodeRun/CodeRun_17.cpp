#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <stack>
using namespace std;

#pragma warning( disable : 4996) // for test

void BigSeq() {
	int countOfSeq, sizeOfSeq;

	cin >> countOfSeq;
	for (size_t i = 0; i < countOfSeq; i++) {
		cin >> sizeOfSeq;
		vector<float> seq(sizeOfSeq);
		for (size_t j = 0; j < seq.size(); j++) {
			cin >> seq[j];
		}
		vector<float> needs = seq;
		sort(needs.begin(), needs.end());
		stack<float> myStack;

		bool allGood = true;
		do {
			if (!seq.empty()) {
				myStack.push(*seq.begin());
				seq.erase(seq.begin());
			}

			while (!myStack.empty() && myStack.top() == *needs.begin()) {
				myStack.pop();
				needs.erase(needs.begin());
			}

			if (!myStack.empty() && seq.empty()) {
				allGood = false;
				break;
			}

		} while (!seq.empty() || !myStack.empty());
		if (allGood)
			cout << 1 << endl;
		else
			cout << 0 << endl;

	}
}
int main()
{
	freopen("input.txt", "r", stdin); // for test

	BigSeq();

	return 0;
}
