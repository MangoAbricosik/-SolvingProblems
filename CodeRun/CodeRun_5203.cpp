#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#pragma warning( disable : 4996) // for test



int main()
{
	freopen("input.txt", "r", stdin); // for test

	float a, b, c;
	cin >> a >> b >> c;
	cout << setprecision(6) << fixed;
	float D, x1, x2;
	D = pow(b, 2) - (4 * a * c);

	if (D < 0) {
		cout << 0 << endl;
		return 0;
	}
	else if (D == 0) {
		x1 = (-b + sqrt(D)) / (2 * a);
		cout << 1 << "\n" << x1 << "\n";
	}
	else {
		cout << 2 << "\n";
		x1 = (-b + sqrt(D)) / (2 * a);
		x2 = (-b - sqrt(D)) / (2 * a);
		if (x1 < x2) {
			cout << x1 << " " << x2 << "\n";
		}
		else {
			cout << x2 << " " << x1 << "\n";
		}
	}



	return 0;
}