#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n, m;
string d[1009];
bool odw[1009][1009];
const pair<int, int> coor[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool check_bounds(int x, int y, pair<int, int> p) {
	if (x + p.first < 0 || x + p.first >= n || y + p.second < 0 || y + p.second >= m) {
		return false;
	}
	return true;
}

void dfs(int x, int y) {
	odw[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int n_x = x + coor[i].first;
		int n_y = y + coor[i].second;
		if (check_bounds(x, y, coor[i]) && !odw[n_x][n_y] && d[n_x][n_y] == '.') {
			dfs(n_x, n_y);
		}
	}
}

int dfs_run() {
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (odw[i][j] == false && d[i][j] == '.') {
				res++;
				dfs(i, j);
			}
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> d[i];
	}
	cout << dfs_run() << "\n";
	return 0;
}
