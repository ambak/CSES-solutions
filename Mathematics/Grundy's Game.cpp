#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MAX = 1500;
int dp[MAX];
bool d[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int i = 3; i <= MAX; i++) {
		for (int j = 1; j < (i + 1) / 2; j++) {
			d[dp[j] ^ dp[i - j]] = true;
		}
		for (int j = 0; j < MAX; j++) {
			if (d[j] == false) {
				dp[i] = j;
				break;
			}
		}
		for (int j = 0; j < MAX; j++) {
			d[j] = false;
		}
	}
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		if (n < MAX) {
			if (dp[n])
				cout << "first\n";
			else
				cout << "second\n";
		} else {
			cout << "first\n";
		}
	}
	return 0;
}
