#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<int> v[200009];
int in[200009];
int out[200009];
int d[200009];
LL t[400009];

void update(int x, LL v) {
	for (; x < 400009; x += x & -x) {
		t[x] += v;
	}
}

LL query(int x) {
	LL res = 0;
	for (; x > 0; x -= x & -x) {
		res += t[x];
	}
	return res;
}

int dfs(int st, int c) {
	in[st] = c;
	for (int it : v[st]) {
		if (!in[it]) {
			c = dfs(it, c + 1);
		}
	}
	out[st] = c + 1;
	return out[st];
}

int main() {
	ios_base::sync_with_stdio(false);
	LL n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> d[i];
	}
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1, 1);
	for (int i = 1; i <= n; i++) {
		update(in[i], d[i]);
	}
	while (q--) {
		int qq, s, x;
		cin >> qq;
		if (qq == 1) {
			cin >> s >> x;
			int tmp = d[s];
			d[s] = x;
			update(in[s], x - tmp);
		} else {
			cin >> s;
			cout << query(out[s]) - query(in[s] - 1) << "\n";
		}
	}
	return 0;
}
