#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		LL k;
		cin >> k;
		LL digits = 9;
		int j = 1;
		while (k > j * digits) {
			k -= j * digits;
			digits *= 10;
			j++;
		}
		digits /= 9;
		LL number = digits + (k / j) - 1;
		if (k % j == 0) {
			cout << number % 10 << "\n";
		} else {
			number++;
			string s = to_string(number);
			cout << s[k % j - 1] << "\n";
		}
	}
	return 0;
}
