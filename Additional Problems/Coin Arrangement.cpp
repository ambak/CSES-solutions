#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int t[100009][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t[i][0];
		t[i][0]--;
	}
	for (int i = 0; i < n; i++) {
		cin >> t[i][1];
		t[i][1]--;
	}
	LL res = 0;
	for (int i = 0; i < n; i++) {
		if (t[i][0] < 0 && t[i][1] > 0) {
			int x = min(abs(t[i][0]), abs(t[i][1]));
			t[i][0] += x;
			t[i][1] -= x;
			res += x;
		} else if (t[i][0] > 0 && t[i][1] < 0) {
			int x = min(abs(t[i][0]), abs(t[i][1]));
			t[i][0] -= x;
			t[i][1] += x;
			res += x;
		}
		t[i + 1][0] += t[i][0];
		t[i + 1][1] += t[i][1];
		res += abs(t[i][0]);
		res += abs(t[i][1]);
		t[i][0] = 0;
		t[i][1] = 0;
	}
	cout << res << "\n";
	return 0;
}
