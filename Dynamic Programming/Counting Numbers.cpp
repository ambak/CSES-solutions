#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL solve(LL x) {
	LL d[20];
	d[0] = 1;
	d[1] = 9;
	for (int i = 2; i < 20; i++) {
		d[i] = d[i - 1] * 9;
	}
	if (x == -1) {
		return 0;
	}
	auto s = to_string(x);
	LL res = 0;
	for (unsigned i = 0; i < s.size(); i++) {
		res += d[i];
	}

	int prev = 0;
	for (unsigned i = 0; i < s.size(); i++) {
		int X = s[i] - '0';
		if (s[i] - '0' > prev) {
			X = s[i] - '0' - 1;
			if (X < 0) X = 0;
		}
		res += d[s.size() - i - 1] * X;
		if (s[i] - '0' == prev) return res;
		prev = s[i] - '0';
	}

	return res + 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	LL a, b;
	cin >> a >> b;

	cout << solve(b) - solve(a - 1) << "\n";

	return 0;
}
