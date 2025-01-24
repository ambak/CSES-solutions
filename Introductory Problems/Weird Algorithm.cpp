#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
	ios_base::sync_with_stdio(false);
	LL n;
	cin >> n;
	while (n != 1) {
		cout << n << " ";
		n = n & 1 ? n * 3 + 1 : n / 2;
	}
	cout << n << "\n";
	return 0;
}
