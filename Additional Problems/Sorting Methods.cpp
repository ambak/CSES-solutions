#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int longest_increasing_subsequence(vector<int> &v) {
	const int INF = 1e9 + 7;
	const int n = v.size();
	vector<int> d(n + 1, INF);
	d[0] = -INF;
	for (auto x : v) {
		int up_pos = upper_bound(d.begin(), d.end(), x) - d.begin();
		if (d[up_pos - 1] < x && x < d[up_pos]) {
			d[up_pos] = x;
		}
	}
	int res = 0;
	for (int i = 0; i <= n; i++) {
		if (d[i] < INF) {
			res = i;
		}
	}
	return res;
}

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

LL f1(vector<int> &v) {
	LL res = 0;
	const int n = v.size();
	for (int i = 0; i < n; i++) {
		update(i + 1, i + 1, i + 1);
	}
	vector<int> d(n + 1);
	for (int i = 0; i < n; i++) {
		d[v[i]] = i + 1;
	}
	for (int i = 1; i <= n; i++) {
		LL q = query(d[i], d[i]);
		res += q - i;
		update(1, d[i], 1);
	}
	return res;
}

int f2(vector<int> v) {
	int res = 0;
	const int n = v.size();
	vector<int> d(n + 1);
	for (int i = 0; i < n; i++) {
		d[v[i]] = i + 1;
	}
	for (int i = 1; i <= n; i++) {
		if (d[i] != i) {
			res++;
			int a = d[i];
			d[i] = i;
			int b = v[i - 1];
			v[i - 1] = i;
			d[b] = a;
			v[a - 1] = b;
		}
	}
	return res;
}

int f3(vector<int> &v) {
	return v.size() - longest_increasing_subsequence(v);
}

int f4(vector<int> &v) {
	int n = v.size();
	auto it = find(v.begin(), v.end(), n);
	n--;
	int res = 1;
	while (it != v.begin()) {
		it--;
		if (*it == n) {
			n--;
			res++;
		}
	}
	return v.size() - res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	LL n;
	cin >> n;
	vector<int> v(n);
	for (auto &x : v) cin >> x;
	cout << f1(v) << " " << f2(v) << " " << f3(v) << " " << f4(v) << "\n";
	return 0;
}
