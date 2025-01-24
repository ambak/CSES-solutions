#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int t[1009][1009];

int main() {
	ios_base::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			int x = j + 1;
			t[i][x] = t[i - 1][x] + t[i][x - 1] - t[i - 1][x - 1];
			if (s[j] == '*') {
				t[i][x]++;
			}
		}
	}
	while (q--) {
		int y1, x1, y2, x2;
		cin >> y1 >> x1 >> y2 >> x2;
		cout << t[y2][x2] + t[y1 - 1][x1 - 1] - t[y2][x1 - 1] - t[y1 - 1][x2] << "\n";
	}

	return 0;
}
