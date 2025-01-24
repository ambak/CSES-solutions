#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

template <typename T, typename U>
std::pair<T, U> operator+(const std::pair<T, U>& l, const std::pair<T, U>& r) {
	return {l.first + r.first, l.second + r.second};
}

int n, m;
int odw[1009][1009];
int odw2[1009][1009];
queue<pair<int, int> > q;

char tab[1009][1009];
pair<int, int> b[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
char B[4] = {'U', 'D', 'L', 'R'};

bool bounds(pair<int, int> b, pair<int, int> a) {
	if (b.first + a.first < 0 || b.first + a.first >= n) {
		return false;
	}
	if (b.second + a.second < 0 || b.second + a.second >= m) {
		return false;
	}
	return true;
}

void bfs_m() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tab[i][j] == 'M') {
				q.push({i, j});
				odw[i][j] = 1;
			}
		}
	}

	while (!q.empty()) {
		auto x = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			if (bounds(x, b[i])) {
				pair<int, int> c = x + b[i];
				if (odw[c.first][c.second] == 0 && tab[c.first][c.second] != '#') {
					odw[c.first][c.second] = odw[x.first][x.second] + 1;
					q.push(c);
				}
			}
		}
	}
}

pair<int, int> res;

bool bfs_a() {
	while (!q.empty()) {
		q.pop();
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tab[i][j] == 'A') {
				q.push({i, j});
				odw2[i][j] = 1;
			}
		}
	}

	while (!q.empty()) {
		auto x = q.front();
		q.pop();
		if (x.first == 0 || x.second == 0 || x.first == n - 1 || x.second == m - 1) {
			res = x;
			return true;
		}
		for (int i = 0; i < 4; i++) {
			if (bounds(x, b[i])) {
				pair<int, int> c = x + b[i];
				int nr = odw2[x.first][x.second] + 1;
				if (odw2[c.first][c.second] == 0 && tab[c.first][c.second] != '#' && (odw[c.first][c.second] > nr || odw[c.first][c.second] == 0)) {
					odw2[c.first][c.second] = odw2[x.first][x.second] + 1;
					q.push(c);
				}
			}
		}
	}
	return false;
}

vector<char> ans;

void bfs_p() {
	while (!q.empty()) {
		q.pop();
	}
	q.push(res);
	while (!q.empty()) {
		auto x = q.front();
		q.pop();
		int nr = odw2[x.first][x.second] - 1;
		if (nr == 0) return;
		for (int i = 0; i < 4; i++) {
			if (bounds(x, b[i])) {
				pair<int, int> c = x + b[i];
				if (odw2[c.first][c.second] == nr) {
					q.push(c);
					ans.push_back(B[i]);
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> tab[i];
	}
	bfs_m();
	if (bfs_a()) {
		cout << "YES\n";
		bfs_p();
		reverse(ans.begin(), ans.end());
		cout << ans.size() << "\n";
		for (auto it : ans) {
			cout << it;
		}
		cout << "\n";
	} else {
		cout << "NO\n";
	}

	return 0;
}
