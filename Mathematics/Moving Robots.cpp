#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

double dp[101][8][8][8][8];

int main() {
	ios_base::sync_with_stdio(false);
	int k;
	cin >> k;

	pair<int, int> m[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			dp[0][i][j][i][j] = 1.0;
		}
	}

	for (int step = 1; step <= k; step++) {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				for (int ii = 0; ii < 8; ii++) {
					for (int jj = 0; jj < 8; jj++) {
						int dz = 0;
						for (int s = 0; s < 4; s++) {
							if (ii + m[s].first >= 0 && ii + m[s].first < 8 && jj + m[s].second >= 0 && jj + m[s].second < 8) {
								dz++;
							}
						}
						for (int s = 0; s < 4; s++) {
							if (ii + m[s].first >= 0 && ii + m[s].first < 8 && jj + m[s].second >= 0 && jj + m[s].second < 8) {
								dp[step][i][j][ii + m[s].first][jj + m[s].second] += dp[step - 1][i][j][ii][jj] / dz;
							}
						}
					}
				}
			}
		}
	}

	double res = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			double p = 1;
			for (int ii = 0; ii < 8; ii++) {
				for (int jj = 0; jj < 8; jj++) {
					p *= 1 - dp[k][ii][jj][i][j];
				}
			}
			res += p;
		}
	}
	cout << fixed << setprecision(6) << res << "\n";
	return 0;
}
