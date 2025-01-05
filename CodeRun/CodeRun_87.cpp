#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

#pragma warning( disable : 4996) // for test

int main()
{
	freopen("input.txt", "r", stdin); // for test

	int wordSize, proposalSize, counter = 0;
	cin >> wordSize >> proposalSize;

	map<char, int> word, proposal;
	for (size_t i = 0; i < wordSize; i++) {
		char temp;
		cin >> temp;
		if (!word.emplace(temp, 1).second) {
			word[temp]++;
		}
	}

	vector<char> myQueue;
	for (size_t i = 0; i < wordSize; i++) {
		char temp;
		cin >> temp;
		myQueue.push_back(temp);
		if (!proposal.emplace(temp, 1).second) {
			proposal[temp]++;
		}
	}
	if (equal(word.begin(), word.end(), proposal.begin(), proposal.end()))
		counter++;


	for (size_t i = wordSize; i < proposalSize; i++) {
		proposal[myQueue.front()]--;
		if (proposal[myQueue.front()] == 0)
			proposal.erase(proposal.find(myQueue.front()));
		myQueue.erase(myQueue.begin());

		char temp;
		cin >> temp;
		myQueue.push_back(temp);
		if (!proposal.emplace(temp, 1).second) {
			proposal[temp]++;
		}

		if (equal(word.begin(), word.end(), proposal.begin(), proposal.end()))
			counter++;
	}

	cout << counter << endl;

	return 0;
}