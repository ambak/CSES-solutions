#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Hamilton_paths_in_grid_graphs {
public:
	bool is_acceptable(int n, int m, int x1, int y1, int x2, int y2) {
		if (x1 == x2 && y1 == y2) return false;

		if (n * m % 2 == 1 && (is_black(x1, y1) || is_black(x2, y2))) return false;
		if (n * m % 2 == 0 && (is_black(x1, y1) == is_black(x2, y2))) return false;

		if (n == 1 && !((y1 == 1 && y2 == m) || (y1 == m && y2 == 1))) return false;
		if (m == 1 && !((x1 == 1 && x2 == n) || (x1 == n && x2 == 1))) return false;

		if (n == 2 && m == 2) return true;
		if (n == 2 && x1 != x2 && (y1 == y2 && y1 != 1 && y1 != m)) return false;
		if (m == 2 && y1 != y2 && (x1 == x2 && x1 != 1 && x1 != n)) return false;

		if (n == 3 && m % 2 == 0) {
			if (is_black(x1, y1) && ((x1 == 2 && y1 < y2) || y1 < y2 - 1)) return false;
			if (!is_black(x1, y1) && ((x2 == 2 && y2 < y1) || y2 < y1 - 1)) return false;
		}
		if (m == 3 && n % 2 == 0) {
			if (is_black(x1, y1) && ((y1 == 2 && x1 < x2) || x1 < x2 - 1)) return false;
			if (!is_black(x1, y1) && ((y2 == 2 && x2 < x1) || x2 < x1 - 1)) return false;
		}
		return true;
	}
	void setup(int _n, int _m, int _x1, int _y1, int _x2, int _y2) {
		n = _n;
		m = _m;
		x1 = _x1;
		y1 = _y1;
		x2 = _x2;
		y2 = _y2;
		res = "";
		v = vector<vector<char>>(n + 2, vector<char>(m + 2));
		w = vector<vector<char>>(n + 2, vector<char>(m + 2));
	}

	void build_path() {
		build(n, m, x1, y1, x2, y2, 0, 0);
	}

	void print() {
		int j = 0;
		int x = x1;
		int y = y1;
		string res;
		while (j < n * m - 1) {
			if (w[x][y])
				res.push_back(w[x][y]);
			else
				res.push_back(v[x][y]);
			j++;
			for (int i = 0; i < 4; i++) {
				if (res.back() == l[i]) {
					x += moves[i].first;
					y += moves[i].second;
					break;
				}
			}
		}
		cout << res << "\n";
	}

private:
	int n, m, x1, y1, x2, y2;
	vector<vector<char>> v, w;
	string res;
	const vector<pair<int, int>> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	const vector<char> l = {'D', 'U', 'R', 'L'};
	map<tuple<int, int, int, int, int, int>, string> prime;

	bool is_black(int x, int y) {
		return (x + y) % 2 == 1;
	}

	void build(int n, int m, int x1, int y1, int x2, int y2, int sx, int sy) {
		if (strip(n, m, x1, y1, x2, y2, sx, sy)) return;
		if (split(n, m, x1, y1, x2, y2, sx, sy)) return;
		auto ans = find(n, m, x1, y1, x2, y2);
		int x = x1 + sx;
		int y = y1 + sy;
		for (auto c : ans) {
			v[x][y] = c;
			for (int i = 0; i < 4; i++) {
				if (c == l[i]) {
					x += moves[i].first;
					y += moves[i].second;
					break;
				}
			}
		}
	}

	bool split(int n, int m, int x1, int y1, int x2, int y2, int sx, int sy) {
		if (n > 4 && x2 - x1 > 2) {
			for (int i = 1; i <= min(4, m); i++) {
				int nn = x1 + (x1 % 2 == 0 ? 2 : 1);
				if (is_acceptable(nn, m, x1, y1, nn, i) && is_acceptable(n - nn, m, 1, i, x2 - nn, y2)) {
					build(nn, m, x1, y1, nn, i, sx, sy);
					w[nn + sx][i + sy] = 'D';
					build(n - nn, m, 1, i, x2 - nn, y2, sx + nn, sy);
					return true;
				}
			}
		}
		if (n > 4 && x1 - x2 > 2) {
			for (int i = 1; i <= min(4, m); i++) {
				int nn = x2 + (x2 % 2 == 0 ? 2 : 1);
				if (is_acceptable(n - nn, m, x1 - nn, y1, 1, i) && is_acceptable(nn, m, nn, i, x2, y2)) {
					build(n - nn, m, x1 - nn, y1, 1, i, sx + nn, sy);
					w[1 + sx + nn][i + sy] = 'U';
					build(nn, m, nn, i, x2, y2, sx, sy);
					return true;
				}
			}
		}
		if (m > 4 && y2 - y1 > 2) {
			for (int i = 1; i <= min(4, n); i++) {
				int mm = y1 + (y1 % 2 == 0 ? 2 : 1);
				if (is_acceptable(n, mm, x1, y1, i, mm) && is_acceptable(n, m - mm, i, 1, x2, y2 - mm)) {
					build(n, mm, x1, y1, i, mm, sx, sy);
					w[i + sx][mm + sy] = 'R';
					build(n, m - mm, i, 1, x2, y2 - mm, sx, sy + mm);
					return true;
				}
			}
		}
		if (m > 4 && y1 - y2 > 2) {
			for (int i = 1; i <= min(4, n); i++) {
				int mm = y2 + (y2 % 2 == 0 ? 2 : 1);
				if (is_acceptable(n, m - mm, x1, y1 - mm, i, 1) && is_acceptable(n, mm, i, mm, x2, y2)) {
					build(n, m - mm, x1, y1 - mm, i, 1, sx, sy + mm);
					w[i + sx][1 + sy + mm] = 'L';
					build(n, mm, i, mm, x2, y2, sx, sy);
					return true;
				}
			}
		}
		return false;
	}

	bool strip(int n, int m, int x1, int y1, int x2, int y2, int sx, int sy) {
		for (int j = 0; j < 3; j++) {
			int minx = min(x1, x2) - 1 - j;
			if (minx > 1 && n - minx > 1) {
				if (is_acceptable(n - minx, m, x1 - minx, y1, x2 - minx, y2)) {
					build(n - minx, m, x1 - minx, y1, x2 - minx, y2, sx + minx, sy);
					for (int i = 1 + sy; i <= m + sy; i++) {
						if (v[minx + 1 + sx][i] == 'L') {
							build(minx, m, minx, i - sy, minx, i - 1 - sy, sx, sy);
							w[minx + 1 + sx][i] = 'U';
							w[minx + sx][i - 1] = 'D';
							return true;
						}
						if (v[minx + 1 + sx][i] == 'R') {
							build(minx, m, minx, i - sy, minx, i + 1 - sy, sx, sy);
							w[minx + 1 + sx][i] = 'U';
							w[minx + sx][i + 1] = 'D';
							return true;
						}
					}
				}
			}
		}

		for (int j = 0; j < 3; j++) {
			int maxx = max(x1, x2) + j;
			if (maxx > 1 && n - maxx > 1) {
				if (is_acceptable(maxx, m, x1, y1, x2, y2)) {
					build(maxx, m, x1, y1, x2, y2, sx, sy);
					for (int i = 1 + sy; i <= m + sy; i++) {
						if (v[maxx + sx][i] == 'L') {
							build(n - maxx, m, 1, i - sy, 1, i - 1 - sy, sx + maxx, sy);
							w[maxx + sx][i] = 'D';
							w[maxx + 1 + sx][i - 1] = 'U';
							return true;
						}
						if (v[maxx + sx][i] == 'R') {
							build(n - maxx, m, 1, i - sy, 1, i + 1 - sy, sx + maxx, sy);
							w[maxx + sx][i] = 'D';
							w[maxx + 1 + sx][i + 1] = 'U';
							return true;
						}
					}
				}
			}
		}

		for (int j = 0; j < 3; j++) {
			int miny = min(y1, y2) - 1 - j;
			if (miny > 1 && m - miny > 1) {
				if (is_acceptable(n, m - miny, x1, y1 - miny, x2, y2 - miny)) {
					build(n, m - miny, x1, y1 - miny, x2, y2 - miny, sx, sy + miny);
					for (int i = 1 + sx; i <= n + sx; i++) {
						if (v[i][miny + 1 + sy] == 'D') {
							build(n, miny, i - sx, miny, i + 1 - sx, miny, sx, sy);
							w[i + 1][miny + sy] = 'R';
							w[i][miny + 1 + sy] = 'L';
							return true;
						}
						if (v[i][miny + 1 + sy] == 'U') {
							build(n, miny, i - sx, miny, i - 1 - sx, miny, sx, sy);
							w[i - 1][miny + sy] = 'R';
							w[i][miny + 1 + sy] = 'L';
							return true;
						}
					}
				}
			}
		}

		for (int j = 0; j < 3; j++) {
			int maxy = max(y1, y2) + j;
			if (maxy > 1 && m - maxy > 1) {
				if (is_acceptable(n, maxy, x1, y1, x2, y2)) {
					build(n, maxy, x1, y1, x2, y2, sx, sy);
					for (int i = 1 + sx; i <= n + sx; i++) {
						if (v[i][maxy + sy] == 'D') {
							build(n, m - maxy, i - sx, 1, i + 1 - sx, 1, sx, sy + maxy);
							w[i + 1][maxy + 1 + sy] = 'L';
							w[i][maxy + sy] = 'R';
							return true;
						}
						if (v[i][maxy + sy] == 'U') {
							build(n, m - maxy, i - sx, 1, i - 1 - sx, 1, sx, sy + maxy);
							w[i - 1][maxy + 1 + sy] = 'L';
							w[i][maxy + sy] = 'R';
							return true;
						}
					}
				}
			}
		}

		return false;
	}

	string find(int n, int m, int x1, int y1, int x2, int y2) {
		auto it = prime.find({n, m, x1, y1, x2, y2});
		if (it != prime.end()) {
			return it->second;
		}
		string ans;
		vector<vector<bool>> odw(n + 1, vector<bool>(m + 1));
		auto dfs = [&](int x, int y, auto&& dfs) -> bool {
			bool res = false;
			if (x == x2 && y == y2) {
				if (int(ans.size()) == n * m - 1) return true;
				return false;
			}
			odw[x][y] = true;
			for (int i = 0; i < 4; i++) {
				const int a = moves[i].first;
				const int b = moves[i].second;
				if (x + a < 1 || x + a > n || y + b < 1 || y + b > m) continue;
				if (odw[x + a][y + b] == false) {
					ans.push_back(l[i]);
					if (dfs(x + a, y + b, dfs)) {
						return true;
					} else {
						ans.pop_back();
					}
				}
			}
			odw[x][y] = false;
			return res;
		};
		dfs(x1, y1, dfs);
		prime[{n, m, x1, y1, x2, y2}] = ans;
		return ans;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int tt;
	cin >> tt;
	auto h = Hamilton_paths_in_grid_graphs();
	while (tt--) {
		int n, m, x1, y1, x2, y2;
		cin >> n >> m >> x1 >> y1 >> x2 >> y2;
		h.setup(n, m, x1, y1, x2, y2);
		if (!h.is_acceptable(n, m, x1, y1, x2, y2)) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
			h.build_path();
			h.print();
		}
	}
	return 0;
}
