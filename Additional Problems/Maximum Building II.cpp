#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

char v[1009][1009];
int up[1009][1009];
int res[1009][1009];

int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> v[i][j];
		}
	}

	for (int j = 1; j <= m; j++) {
		for (int i = 1; i <= n; i++) {
			if (v[i][j] == '.') {
				up[i][j] = up[i - 1][j] + 1;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		stack<pair<int, int>> s;
		for (int j = 1; j <= m + 1; j++) {
			int width = 0;
			while (!s.empty() && s.top().first >= up[i][j]) {
				width += s.top().second;
				res[s.top().first + 1][width]--;
				s.pop();
				int height = max(up[i][j], (s.empty() ? 0 : s.top().first));
				res[height + 1][width]++;
			}
			s.push({up[i][j], width + 1});
		}
	}

	for (int i = 1; i <= n; i++) {
		int sum1 = 0;
		int sum2 = 0;
		for (int j = m; j > 0; j--) {
			sum1 += res[i][j];
			sum2 += sum1;
			res[i][j] = res[i - 1][j] + sum2;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << res[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
