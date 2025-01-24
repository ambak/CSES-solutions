#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<int> v[200009];
int in[200009];
int out[200009];
int d[200009];

const int M = 1 << 19;
pair<LL, LL> t[M * 2 + 5];

void update(int a, int b, LL v) {
	a += M;
	b += M;
	t[a].first += v;
	if (a != b) t[b].first += v;
	int pow = 1;
	while (a / 2 != b / 2) {
		if ((a & 1) == 0) {
			t[a + 1].second += v;
		}
		if ((b & 1) == 1) {
			t[b - 1].second += v;
		}
		a /= 2;
		b /= 2;
		t[a].first = t[a * 2].first + t[a * 2 + 1].first + t[a * 2].second * pow + t[a * 2 + 1].second * pow;
		t[b].first = t[b * 2].first + t[b * 2 + 1].first + t[b * 2].second * pow + t[b * 2 + 1].second * pow;
		pow *= 2;
	}
	while (a != 1) {
		a /= 2;
		t[a].first = t[a * 2].first + t[a * 2 + 1].first + t[a * 2].second * pow + t[a * 2 + 1].second * pow;
		pow *= 2;
	}
}

LL query(int a, int b) {
	a += M;
	b += M;
	LL res = t[a].first;
	if (a != b) res += t[b].first;
	int pow = 1;
	int diff = b - a + 1;
	int counta = 1;
	int countb = 1;
	while (a / 2 != b / 2) {
		res += t[a].second * counta + t[b].second * countb;
		if ((a & 1) == 0) {
			res += t[a + 1].first + t[a + 1].second * pow;
			counta += pow;
		}
		if ((b & 1) == 1) {
			res += t[b - 1].first + t[b - 1].second * pow;
			countb += pow;
		}
		a /= 2;
		b /= 2;
		pow *= 2;
	}
	res += t[a].second * counta;
	if (a != b) res += t[b].second * countb;
	a /= 2;
	while (a != 0) {
		res += t[a].second * diff;
		a /= 2;
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
		update(in[i], out[i], d[i]);
	}
	while (q--) {
		int qq, s, x;
		cin >> qq;
		if (qq == 1) {
			cin >> s >> x;
			int tmp = d[s];
			d[s] = x;
			update(in[s], out[s], x - tmp);
		} else {
			cin >> s;
			cout << query(in[s], in[s]) << "\n";
		}
	}
	return 0;
}
