#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class tree {
public:
	static const int M = 1 << 10;
	string s[M + 5];
	tree() {
		for (int i = 0; i < 2 * M; i++) {
			for (int j = 0; j < 2 * M; j++) {
				d[i][j] = 0;
			}
		}
	}
	void update(int x, int y, int v) {
		x += M;
		update_1(y, v, x);
		x /= 2;
		while (x != 0) {
			update_1(y, v, x);
			x /= 2;
		}
	}

	LL query(int x1, int y1, int x2, int y2) {
		x1 += M;
		x2 += M;
		LL res = query_1(y1, y2, x1);
		if (x1 != x2) res += query_1(y1, y2, x2);
		while (x1 / 2 != x2 / 2) {
			if ((x1 & 1) == 0) res += query_1(y1, y2, x1 + 1);
			if ((x2 & 1) == 1) res += query_1(y1, y2, x2 - 1);
			x1 /= 2;
			x2 /= 2;
		}
		return res;
	}

private:
	void update_1(int a, LL v, int dim) {
		a += M;
		d[dim][a] += v;
		a /= 2;
		while (a != 0) {
			int l = 2 * a;
			int r = 2 * a + 1;
			d[dim][a] = d[dim][l] + d[dim][r];
			a /= 2;
		}
	}

	LL query_1(int a, int b, int dim) {
		a += M;
		b += M;
		LL res = d[dim][a];
		if (a != b) res += d[dim][b];
		while (a / 2 != b / 2) {
			if ((a & 1) == 0) res += d[dim][a + 1];
			if ((b & 1) == 1) res += d[dim][b - 1];
			a /= 2;
			b /= 2;
		}
		return res;
	}
	vector<vector<LL>> d = vector<vector<LL>>(2 * M, vector<LL>(2 * M, 0));
};

int main() {
	tree t;
	int n, q;
	ios_base::sync_with_stdio(false);
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> t.s[i];
		for (int j = 0; j < n; j++) {
			if (t.s[i][j] == '*') {
				t.update(i, j, 1);
			}
		}
	}
	while (q--) {
		int qq;
		cin >> qq;
		if (qq == 1) {
			int x, y;
			cin >> x >> y;
			x--;
			y--;
			if (t.s[x][y] == '*') {
				t.s[x][y] = '.';
				t.update(x, y, -1);
			} else {
				t.s[x][y] = '*';
				t.update(x, y, 1);
			}
		} else {
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			x1--;
			y1--;
			x2--;
			y2--;
			cout << t.query(x1, y1, x2, y2) << "\n";
		}
	}
	return 0;
}
