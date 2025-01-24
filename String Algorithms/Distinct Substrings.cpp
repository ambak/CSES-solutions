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

int main() {
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	LL n = s.size();
	auto p = suffix_array(s);
	auto lcp = LCP_array(s, p);
	LL res = (n * n + n) / 2;
	for (int i = 0; i < n; i++) {
		res -= lcp[i];
	}
	cout << res << "\n";
	return 0;
}
