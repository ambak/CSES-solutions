#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	map<int, int> m;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		m[x] = i;
	}
	vector<int> v(n + 1);
	vector<int> w(n + 1);
	int id = 1;
	for (auto [a, pos] : m) {
		v[pos] = id;
		w[id] = pos;
		id++;
		update(pos, n + 1, 1);
	}
	LL res = 0;
	int N = n;
	for (int i = 1; i <= n; i++) {
		int pos = query(w[i], w[i]);
		res += min(pos - 1, N - pos);
		N--;
		update(w[i], n + 1, -1);
	}
	cout << res << "\n";
	return 0;
}
