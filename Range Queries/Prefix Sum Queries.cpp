#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int M = 1 << 19;

// first - sum; second - max prefix
pair<LL, LL> t[M * 2 + 5];

void update(int a, LL v) {
	a += M;
	t[a].first = v;
	t[a].second = max(0LL, v);
	a /= 2;
	while (a != 0) {
		int l = 2 * a;
		int r = 2 * a + 1;
		LL pref = max(t[l].second, t[l].first + t[r].second);
		t[a] = {t[l].first + t[r].first, pref};
		a /= 2;
	}
}

LL query(int a, int b) {
	a += M;
	b += M;
	vector<int> bb;
	bb.push_back(b);
	LL sum = t[a].first;
	LL pref = t[a].second;
	while (a / 2 != b / 2) {
		if ((a & 1) == 0) {
			pref = max(pref, sum + t[a + 1].second);
			sum += t[a + 1].first;
		}
		a /= 2;
		b /= 2;
		bb.push_back(b);
	}
	bb.pop_back();
	reverse(bb.begin(), bb.end());
	for (auto b : bb) {
		if ((b & 1) == 1) {
			pref = max(pref, sum + t[b - 1].second);
			sum += t[b - 1].first;
		}
	}
	pref = max(pref, sum + t[bb.back()].second);
	return pref;
}

int main() {
	int n, q;
	ios_base::sync_with_stdio(false);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		LL x;
		cin >> x;
		update(i, x);
	}
	while (q--) {
		LL a, b, c;
		cin >> c >> a >> b;
		if (c == 1) {
			update(a, b);
		} else {
			cout << query(a, b) << "\n";
		}
	}
	return 0;
}
