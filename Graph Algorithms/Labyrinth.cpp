#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n, m;
string d[1009];
char odw[1009][1009];
const pair<int, int> coor[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const char direction[4] = {'D', 'U', 'R', 'L'};
queue<pair<int, int> > q;

bool check_bounds(int x, int y, pair<int, int> p) {
	if (x + p.first < 0 || x + p.first >= n || y + p.second < 0 || y + p.second >= m) {
		return false;
	}
	return true;
}

bool bfs(pair<int, int> a) {
	int x = a.first;
	int y = a.second;
	odw[x][y] = 'A';
	q.push(a);

	while (!q.empty()) {
		auto a = q.front();
		x = a.first;
		y = a.second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int n_x = x + coor[i].first;
			int n_y = y + coor[i].second;
			if (check_bounds(x, y, coor[i]) && !odw[n_x][n_y] && d[n_x][n_y] == '.') {
				odw[n_x][n_y] = direction[i];
				q.push({n_x, n_y});
			} else if (check_bounds(x, y, coor[i]) && !odw[n_x][n_y] && d[n_x][n_y] == 'B') {
				odw[n_x][n_y] = direction[i];
				return true;
			}
		}
	}
	return false;
}

void bfs_run() {
	pair<int, int> A;
	pair<int, int> B;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (d[i][j] == 'A') {
				A.first = i;
				A.second = j;
			}
			if (d[i][j] == 'B') {
				B.first = i;
				B.second = j;
			}
		}
	}
	string answer;
	bool res = bfs(A);
	if (res) {
		cout << "YES\n";
		int i = B.first;
		int j = B.second;
		while (i != A.first || j != A.second) {
			answer += odw[i][j];
			for (int it = 0; it < 4; it++) {
				if (odw[i][j] == direction[it]) {
					i -= coor[it].first;
					j -= coor[it].second;
					break;
				}
			}
		}
		reverse(answer.begin(), answer.end());
		cout << answer.size() << "\n"
			 << answer << "\n";
	} else {
		cout << "NO\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> d[i];
	}
	bfs_run();
	return 0;
}
