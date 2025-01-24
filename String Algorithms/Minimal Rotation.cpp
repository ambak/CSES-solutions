#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int P[2000009];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	s += s;
	int n = s.size();
	P[0] = -1;
	int t = P[0];
	int rot = 0;
	for (int i = 1; i < n; i++) {
		while (t >= 0 && s[i] != s[t + rot + 1]) {
			if (s[i] > s[t + rot + 1]) {
				t = P[t];
			} else {
				rot = i - t - 1;
				t = P[t];
			}
		}
		if (s[i] != s[t + rot + 1]) {
			if (s[i] < s[t + rot + 1]) {
				rot = i;
			}
			P[i - rot] = -1;
		} else {
			t++;
			P[i - rot] = t;
		}
	}
	for (int i = rot; i < rot + n / 2; i++) {
		cout << s[i];
	}
	cout << "\n";
	return 0;
}
