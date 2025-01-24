#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<int> KMP(string s) {
	vector<int> P(s.size());
	P[0] = 0;
	int t = P[0];
	for (int i = 1; i < int(s.size()); i++) {
		while (t > 0 && s[t] != s[i]) t = P[t - 1];
		if (s[t] == s[i]) t++;
		P[i] = t;
	}
	return P;
}

vector<int> z_function(string s) {
	int l = 0, r = 0;
	int n = s.size();
	vector<int> z(n);
	for (int i = 1; i < n; i++) {
		if (i >= r) {
			while (i + z[i] < n && s[i + z[i]] == s[z[i]]) {
				z[i]++;
			}
			if (z[i]) {
				l = i;
				r = z[i] + i - 1;
			}
		} else {
			z[i] = min(z[i - l], r - i + 1);
			if (z[i - l] >= r - i + 1) {
				while (i + z[i] < n && s[i + z[i]] == s[z[i]]) {
					z[i]++;
				}
				if (z[i] > z[i - l]) {
					l = i;
					r = z[i] + i - 1;
				}
			}
		}
	}
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	auto a = z_function(s);
	for (auto x : a) cout << x << " ";
	cout << "\n";
	a = KMP(s);
	for (auto x : a) cout << x << " ";
	cout << "\n";
	return 0;
}
