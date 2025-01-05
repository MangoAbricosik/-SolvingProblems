#include <iostream>
#include <string>
#include <map>

using namespace std;

#pragma warning( disable : 4996) // for test

int main()
{
	freopen("input.txt", "r", stdin); // for test

	map<string, int> dataBase;
	string str_temp;
	int int_temp;

	while (cin >> str_temp) {
		if (str_temp == "DEPOSIT") {
			cin >> str_temp; cin >> int_temp;
			if (dataBase.find(str_temp) == dataBase.end()) {
				dataBase.emplace(str_temp, int_temp);
			}
			else {
				dataBase[str_temp] += int_temp;
			}
		}
		else if (str_temp == "WITHDRAW") {
			cin >> str_temp; cin >> int_temp;
			if (dataBase.find(str_temp) == dataBase.end()) {
				dataBase.emplace(str_temp, -int_temp);
			}
			else {
				dataBase[str_temp] -= int_temp;
			}
		}
		else if (str_temp == "BALANCE") {
			cin >> str_temp;
			if (dataBase.find(str_temp) == dataBase.end()) {
				cout << "ERROR" << endl;
			}
			else {
				cout << dataBase[str_temp] << endl;
			}
		}
		else if (str_temp == "TRANSFER") {
			string second_str_temp;
			cin >> str_temp >> second_str_temp >> int_temp;

			if (dataBase.find(str_temp) == dataBase.end()) {
				dataBase.emplace(str_temp, -int_temp);
			}
			else {
				dataBase[str_temp] -= int_temp;
			}
			////////////
			if (dataBase.find(second_str_temp) == dataBase.end()) {
				dataBase.emplace(second_str_temp, int_temp);
			}
			else {
				dataBase[second_str_temp] += int_temp;
			}
		}
		else if (str_temp == "INCOME") {
			cin >> int_temp;
			for (auto it = dataBase.begin(); it != dataBase.end(); it++) {
				if (it->second > 0)
					it->second += int(((double)it->second / (double)100) * (double)int_temp);
			}
		}
	}
	return 0;
}