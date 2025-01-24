#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int M = 1 << 19;
pair<LL, LL> t[2 * M + 5];
LL d[M];

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
	int n, q;
	ios_base::sync_with_stdio(false);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> d[i];
	}
	vector<tuple<int, int, int>> queries;
	for (int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b;
		queries.emplace_back(a, b, i);
	}
	sort(queries.begin(), queries.end());
	reverse(queries.begin(), queries.end());
	vector<LL> res(q);
	vector<pair<int, int>> ranges;
	ranges.emplace_back(n, n);
	int id = n;
	for (auto [a, b, i] : queries) {
		while (a < id) {
			int j = id - 1;
			if (d[j] <= d[id]) {
				ranges.emplace_back(j, j);
			} else {
				auto tmp = ranges.back();
				while (!ranges.empty()) {
					auto [A, B] = ranges.back();
					if (d[j] <= d[A]) {
						break;
					}
					ranges.pop_back();
					update(A, B, d[j] - d[A]);
					tmp = make_pair(j, B);
				}
				ranges.push_back(tmp);
			}
			id--;
		}
		res[i] = query(a, b);
	}
	for (auto x : res) {
		cout << x << "\n";
	}
	return 0;
}
