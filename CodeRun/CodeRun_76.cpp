#include <iostream>
#include <string>
#include <vector>

using namespace std;

#pragma warning( disable : 4996) // for test

int main()
{
	freopen("input.txt", "r", stdin); // for test

	int allMetallKG, oneBlankKG, oneDetailKG, blanksHave = 0, detailHave = 0;

	cin >> allMetallKG >> oneBlankKG >> oneDetailKG;

	if (oneDetailKG > oneBlankKG) {
		cout << 0 << "\n";
		return 0;
	}

	while (allMetallKG >= oneBlankKG) {
		blanksHave += allMetallKG / oneBlankKG;
		allMetallKG %= oneBlankKG;

		detailHave += (oneBlankKG / oneDetailKG) * blanksHave;
		allMetallKG += (oneBlankKG % oneDetailKG) * blanksHave;
		blanksHave = 0;
	}

	cout << detailHave << "\n";

	return 0;
}