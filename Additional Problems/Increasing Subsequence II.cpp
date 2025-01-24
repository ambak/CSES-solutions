#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL MOD = 1e9 + 7;
const int M = 1 << 18;
LL t[M];

void update(int x, LL v) {
	for (; x < M; x += x & -x) {
		t[x] = (t[x] + v) % MOD;
	}
}

LL query(int x) {
	LL res = 0;
	for (; x > 0; x -= x & -x) {
		res = (res + t[x]) % MOD;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	vector<int> w(n);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v[i] = {x, i};
	}
	sort(v.begin(), v.end());
	int id = 1;
	int prev = 0;
	for (auto [a, b] : v) {
		if (a != prev) {
			prev = a;
			id++;
		}
		w[b] = id;
	}
	LL res = 0;
	reverse(w.begin(), w.end());
	for (auto x : w) {
		LL tmp = (query(M - 1) - query(x) + 1 + MOD) % MOD;
		res = (res + tmp + MOD) % MOD;
		update(x, tmp);
	}
	cout << res << "\n";
	return 0;
}
