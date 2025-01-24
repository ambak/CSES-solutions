#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL t[30];
int n;
LL res = 99999999999999999L;
LL sum;

void solve(int st, LL left) {
	res = min(res, abs(sum - left - left));
	if (st == n) return;
	solve(st + 1, left);
	solve(st + 1, left + t[st]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t[i];
		sum += t[i];
	}
	solve(0, 0);
	cout << res << "\n";

	return 0;
}
