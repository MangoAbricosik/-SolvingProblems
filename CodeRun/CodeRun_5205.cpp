#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

#pragma warning( disable : 4996) // for test

long long GCD(long long a, long long b) {
	return b ? GCD(b, a % b) : a;
}

long long LCM(long long a, long long b) {
	return a / GCD(a, b) * b;
}

int main()
{
	freopen("input.txt", "r", stdin); // for test

	long long first, second;
	cin >> first >> second;

	cout << GCD(first, second) << " " << LCM(first, second);

	return 0;
}