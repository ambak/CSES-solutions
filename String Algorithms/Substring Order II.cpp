#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<int> sort_cyclic_shifts(string s) {
	int n = s.size();
	int alphabet = 200;
	vector<int> p(n), c(n), cnt(max(alphabet, n));
	for (int i = 0; i < n; i++) {
		cnt[s[i]]++;
	}
	for (int i = 0; i < alphabet; i++) {
		cnt[i] += cnt[i - 1];
	}
	for (int i = 0; i < n; i++) {
		cnt[s[i]]--;
		p[cnt[s[i]]] = i;
	}
	int lvl = 0;
	for (int i = 1; i < n; i++) {
		if (s[p[i - 1]] != s[p[i]]) {
			lvl++;
		}
		c[p[i]] = lvl;
	}
	vector<int> pn(n), cn(n);
	for (int k = 0; (1 << k) < n; k++) {
		for (int i = 0; i < n; i++) {
			pn[i] = p[i] - (1 << k);
			if (pn[i] < 0) {
				pn[i] += n;
			}
		}
		for (int i = 0; i < max(n, alphabet); i++) {
			cnt[i] = 0;
		}
		for (int i = 0; i < n; i++) {
			cnt[c[pn[i]]]++;
		}
		for (int i = 1; i <= lvl; i++) {
			cnt[i] += cnt[i - 1];
		}
		for (int i = n - 1; i >= 0; i--) {
			cnt[c[pn[i]]]--;
			p[cnt[c[pn[i]]]] = pn[i];
		}
		lvl = 0;
		for (int i = 1; i < n; i++) {
			pair<int, int> a = {c[p[i]], c[(p[i] + (1 << k)) % n]};
			pair<int, int> b = {c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n]};
			if (a != b) {
				lvl++;
			}
			cn[p[i]] = lvl;
		}
		swap(c, cn);
	}
	return p;
}

vector<int> suffix_array(string s) {
	s += '$';
	auto shifts = sort_cyclic_shifts(s);
	shifts.erase(shifts.begin());
	return shifts;
}

vector<int> LCP_array(string s, vector<int> p) {
	int n = s.size();
	vector<int> rank(n, 0);
	for (int i = 0; i < n; i++) {
		rank[p[i]] = i;
	}
	int k = 0;
	vector<int> lcp(n);
	for (int i = 0; i < n; i++) {
		if (rank[i] == n - 1) {
			k = 0;
			continue;
		}
		int j = p[rank[i] + 1];
		while (i + k < n && j + k < n && s[i + k] == s[j + k]) {
			k++;
		}
		lcp[rank[i]] = k;
		if (k) {
			k--;
		}
	}
	return lcp;
}

const int M = 1 << 19;
pair<int, int> t[M * 2 + 5];
pair<int, int> tt[M * 2 + 5];
int t2[M * 2 + 5];
int t3[M * 2 + 5];

void update_first(int a, pair<int, int> v) {
	a += M;
	t[a] = v;
	a /= 2;
	while (a != 0) {
		int l = 2 * a;
		int r = 2 * a + 1;
		t[a] = min(t[l], t[r]);
		a /= 2;
	}
}

pair<int, int> query_first(int a, int b) {
	a += M;
	b += M;
	pair<int, int> res = min(t[a], t[b]);
	while (a / 2 != b / 2) {
		if ((a & 1) == 0) res = min(res, t[a + 1]);
		if ((b & 1) == 1) res = min(res, t[b - 1]);
		a /= 2;
		b /= 2;
	}
	return res;
}

pair<int, int> min_last(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		if (a.second > b.second) {
			return a;
		}
		return b;
	}
	if (a.first < b.first) {
		return a;
	}
	return b;
}

void update_last(int a, pair<int, int> v) {
	a += M;
	tt[a] = v;
	a /= 2;
	while (a != 0) {
		int l = 2 * a;
		int r = 2 * a + 1;
		tt[a] = min_last(tt[l], tt[r]);
		a /= 2;
	}
}

pair<int, int> query_last(int a, int b) {
	a += M;
	b += M;
	pair<int, int> res = min_last(tt[a], tt[b]);
	while (a / 2 != b / 2) {
		if ((a & 1) == 0) res = min_last(res, tt[a + 1]);
		if ((b & 1) == 1) res = min_last(res, tt[b - 1]);
		a /= 2;
		b /= 2;
	}
	return res;
}

void update_range(int a, int b, int v) {
	a += M;
	b += M;
	t2[a] = min(t2[a], v);
	t2[b] = min(t2[b], v);
	while (a / 2 != b / 2) {
		if ((a & 1) == 0) t2[a + 1] = min(v, t2[a + 1]);
		if ((b & 1) == 1) t2[b - 1] = min(v, t2[b - 1]);
		a /= 2;
		b /= 2;
	}
}

int query_range(int a) {
	a += M;
	int res = t2[a];
	while (a > 0) {
		res = min(res, t2[a]);
		a /= 2;
	}
	return res;
}

void update_used(int a, int b, int v) {
	a += M;
	b += M;
	t3[a] = max(t3[a], v);
	t3[b] = max(t3[b], v);
	while (a / 2 != b / 2) {
		if ((a & 1) == 0) t3[a + 1] = max(v, t3[a + 1]);
		if ((b & 1) == 1) t3[b - 1] = max(v, t3[b - 1]);
		a /= 2;
		b /= 2;
	}
}

int query_used(int a) {
	a += M;
	int res = t3[a];
	while (a > 0) {
		res = max(res, t3[a]);
		a /= 2;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	LL k;
	cin >> k;
	LL n = s.size();
	auto p = suffix_array(s);
	auto lcp = LCP_array(s, p);

	for (int i = 0; i < n; i++) {
		update_first(i, {lcp[i], i});
		update_last(i, {lcp[i], i});
	}
	for (int i = 0; i < 2 * M; i++) {
		t2[i] = n - 1;
	}
	int j = 0;
	int length = 0;
	for (int i = 0; i < n; i++) {
		bool found = false;
		int len = 0;
		int e = query_range(i) - 1;
		while (e >= i) {
			auto [l, id1] = query_first(i, e);
			auto [l2, id2] = query_last(i, e);
			int x = e - i + 2;
			len = query_used(i);
			if (k > (l - len) * x) {
				k -= (l - len) * x;
			} else {
				while (len < l) {
					if (k > x) {
						k -= x;
					} else {
						found = true;
						j = i;
						length = len + 1;
						break;
					}
					len++;
				}
			}
			if (found) {
				break;
			}
			update_used(i, e + 1, lcp[id2]);
			update_range(i, id2, id2);
			update_range(i, id1, id1);
			e = id1 - 1;
		}
		if (found) {
			break;
		}
		len = lcp[i];
		if (i - 1 >= 0) {
			len = max(len, lcp[i - 1]);
		}
		if (k > n - p[i] - len) {
			k -= n - p[i] - len;
		} else {
			j = i;
			length = len + k;
			break;
		}
	}

	for (int i = 0; i < length; i++) {
		cout << s[p[j] + i];
	}
	cout << "\n";
	return 0;
}
