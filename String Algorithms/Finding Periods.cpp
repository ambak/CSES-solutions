#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<int> z_function(string &s) {
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
	string s;
	cin >> s;
	auto z = z_function(s);
	int n = s.size();
	for (int i = 0; i < n; i++) {
		if (z[i] == n - i) {
			cout << i << " ";
		}
	}
	cout << n << "\n";
	return 0;
}
