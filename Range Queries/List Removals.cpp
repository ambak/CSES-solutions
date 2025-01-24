#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int M = 1 << 20;
pair<int, int> t[M * 4 + 5];
int d[M];

void update(int a, int b, int OD, int DO, int c, int v) {
	int sr = OD + (DO - OD) / 2;
	if (a <= OD && b >= DO) {
		t[c].second += v;
		return;
	}
	if (a <= sr) {
		update(a, b, OD, sr, c * 2, v);
	}
	if (b > sr) {
		update(a, b, sr + 1, DO, c * 2 + 1, v);
	}
	t[c].first = max(t[c * 2].first + t[c * 2].second, t[c * 2 + 1].first + t[c * 2 + 1].second);
}

int query(int a, int OD, int DO, int c, int v) {
	if (OD == DO) {
		return OD;
	}
	v += t[c].second;
	int sr = OD + (DO - OD) / 2;
	if (t[c * 2].first + t[c * 2].second + v >= a) {
		return query(a, OD, sr, c * 2, v);
	} else {
		return query(a, sr + 1, DO, c * 2 + 1, v);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> d[i];
		update(i, i, 0, M, 1, i);
	}
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		int x = query(a, 0, M, 1, 0);
		cout << d[x] << " ";
		update(x, x, 0, M, 1, -x);
		update(x + 1, M, 0, M, 1, -1);
	}
	return 0;
}
