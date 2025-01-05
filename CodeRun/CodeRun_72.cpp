#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;
int main() {
	int temp, last = INT_MIN;
	while (cin >> temp)
	{
		if (temp > last)
		{
			last = temp;
			continue;
		}
		else
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;	
}