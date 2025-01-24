#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int t[8][8];
int m[8][2] = {{1, 2}, {2, 1}, {-1, 2}, {-2, 1}, {1, -2}, {2, -1}, {-1, -2}, {-2, -1}};

bool check_m(int x, int y, int id) {
	int X = x + m[id][0];
	int Y = y + m[id][1];
	if (X >= 0 && X < 8 && Y >= 0 && Y < 8 && t[X][Y] == 0) {
		return true;
	}
	return false;
}

bool tour(int x, int y, int c) {
	t[x][y] = c;
	if (c == 64) return true;
	vector<pair<int, int> > v;
	for (int i = 0; i < 8; i++) {
		if (check_m(x, y, i)) {
			int r = 0;
			for (int j = 0; j < 8; j++) {
				if (check_m(x + m[i][0], y + m[i][1], j)) {
					r++;
				}
			}
			v.emplace_back(r, i);
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < 8; i++) {
		if (tour(x + m[v[i].second][0], y + m[v[i].second][1], c + 1)) {
			return true;
		}
	}
	t[x][y] = 0;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	int x, y;
	cin >> y >> x;
	x--;
	y--;
	tour(x, y, 1);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cout << t[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
