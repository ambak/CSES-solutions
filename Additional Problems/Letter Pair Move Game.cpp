#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<string> res;

bool check(string &s) {
	bool firstb = false;
	for (auto x : s) {
		if (firstb == false && x == 'B') {
			firstb = true;
		} else if (firstb && x == 'A') {
			return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	string s;
	cin >> n >> s;
	n *= 2;
	bool ok = true;
	int cnt = 0;
	while (!check(s)) {
		cnt++;
		if (cnt > 10 * n) {
			ok = false;
			break;
		}
		if (s.back() == '.') {
			for (int i = n - 1; i > 0; i--) {
				if (s[i] == 'B') {
					swap(s[n - 1], s[i]);
					swap(s[n - 2], s[i - 1]);
					break;
				}
			}
			res.push_back(s);
			continue;
		}
		if (s.back() == 'A' && s[n - 2] != '.') {
			for (int i = n - 1; i > 0; i--) {
				if (s[i] == '.') {
					swap(s[n - 1], s[i]);
					swap(s[n - 2], s[i - 1]);
					break;
				}
			}
			res.push_back(s);
			continue;
		}
		if (s.back() == 'A' && s[n - 2] == '.') {
			if (n - 5 < 0) {
				ok = false;
				break;
			}
			swap(s[n - 2], s[n - 4]);
			swap(s[n - 3], s[n - 5]);
			res.push_back(s);
			continue;
		}
		for (int i = 0; i < n - 1; i++) {
			if (s[i] == '.') {
				for (int j = i + 1; j < n - 1; j++) {
					if (s[j] == 'A') {
						swap(s[i], s[j]);
						swap(s[i + 1], s[j + 1]);
						break;
					}
				}
				res.push_back(s);
				break;
			} else if (s[i] == 'B' && s[i + 1] != '.') {
				for (int j = i + 1; j < n - 1; j++) {
					if (s[j] == '.') {
						swap(s[i], s[j]);
						swap(s[i + 1], s[j + 1]);
						break;
					}
				}
				res.push_back(s);
				break;
			}
		}
	}

	if (ok == false) {
		cout << "-1\n";
	} else {
		cout << res.size() << "\n";
		for (auto &x : res) {
			cout << x << "\n";
		}
	}
	return 0;
}
