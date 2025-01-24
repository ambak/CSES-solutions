#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL MOD = 1e9 + 7;
LL BC[505][505];
LL fact[505];
LL C[10];
int p[505];
int q[505];
bool ip[505];
bool iq[505];

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		p[i] = -1;
		q[i] = -1;
	}
	BC[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		BC[i][0] = 1;
		for (int j = 1; j <= n; j++) {
			BC[i][j] = (BC[i - 1][j - 1] + BC[i - 1][j]) % MOD;
		}
	}
	fact[0] = 1;
	for (int i = 1; i <= n; i++) {
		fact[i] = (fact[i - 1] * i) % MOD;
	}
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			if (s[j] == 'A') {
				p[i] = j;
				ip[j] = true;
			} else if (s[j] == 'B') {
				q[i] = j;
				iq[j] = true;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (p[i] == -1 && q[i] == -1) {
			C[1]++;
		} else if (p[i] == -1 && q[i] != -1 && ip[q[i]] == false) {
			C[2]++;
		} else if (p[i] != -1 && q[i] == -1 && iq[p[i]] == false) {
			C[3]++;
		}
	}

	for (int i = 0; i < n; i++) {
		if (ip[i] == false && iq[i] == false) {
			C[4]++;
		}
		if (ip[i] == false) {
			C[5]++;
		}
		if (iq[i] == false) {
			C[6]++;
		}
	}

	LL res = 0;
	for (int i = 0; i <= min(C[1], C[4]); i++) {
		for (int j = 0; j <= C[2]; j++) {
			for (int k = 0; k <= C[3]; k++) {
				LL tmp = BC[C[1]][i] * BC[C[2]][j] % MOD * BC[C[3]][k] % MOD * BC[C[4]][i] % MOD;
				tmp = tmp * fact[i] % MOD * fact[C[5] - i - j] % MOD * fact[C[6] - i - k] % MOD;
				if ((i + k + j) % 2 == 1) {
					tmp = (-tmp + MOD) % MOD;
				}
				res = (res + tmp) % MOD;
			}
		}
	}
	cout << res << "\n";
	return 0;
}
