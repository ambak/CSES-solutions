#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

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
	string s, p;
	cin >> s >> p;
	auto z = z_function(p + s);
	int res = 0;
	for (unsigned i = p.size(); i < p.size() + s.size(); i++) {
		if (z[i] >= (int)p.size()) {
			res++;
		}
	}
	cout << res << "\n";
	return 0;
}
