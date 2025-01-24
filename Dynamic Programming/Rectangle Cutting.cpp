#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int m[503][503];

int solve(int a, int b) {
	if (a > b) {
		swap(a, b);
	}
	if (m[a][b] != 0) {
		return m[a][b];
	}
	if (a == b) {
		return 0;
	}
	int res = 999999999;
	for (int i = 1; i < a; i++) {
		res = min(res, solve(a - i, b) + solve(i, b) + 1);
	}
	for (int i = 1; i < b; i++) {
		res = min(res, solve(a, b - i) + solve(a, i) + 1);
	}
	m[a][b] = res;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	int a, b;
	cin >> a >> b;
	cout << solve(a, b) << "\n";
	return 0;
}
