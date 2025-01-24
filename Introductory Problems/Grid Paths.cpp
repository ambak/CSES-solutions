#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

bool visited[7][7];
const int moves[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const char moves_names[4] = {'D', 'R', 'U', 'L'};
string path;
vector<string> v;

void dfs(int x, int y, int step) {
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		const int X = x + moves[i][0];
		const int Y = y + moves[i][1];
		if (X == 6 && Y == 0 && step == 47) {
			path.push_back(moves_names[i]);
			v.push_back(path);
			path.pop_back();
		} else if (X >= 0 && X <= 6 && Y >= 0 && Y <= 6) {
			if (visited[X][Y] == false) {
				if (!(X == 6 && Y == 0) && step < 47) {
					if ((X == 6 && Y < 6 && visited[X][Y + 1] == false) || (X > 0 && Y == 6 && visited[X - 1][Y] == false)) {
						continue;
					}
					if ((X == 0 && Y < 6 && visited[X][Y + 1] == false && visited[X][Y - 1] == false) || (X < 6 && Y == 0 && visited[X + 1][Y] == false && visited[X - 1][Y] == false)) {
						continue;
					}
					if (X > 0 && X < 6 && Y > 0 && Y < 6 && ((visited[X][Y + 1] == true && visited[X][Y - 1] == true && visited[X - 1][Y] == false && visited[X + 1][Y] == false) || (visited[X][Y + 1] == false && visited[X][Y - 1] == false && visited[X - 1][Y] == true && visited[X + 1][Y] == true))) {
						continue;
					}
					if (X > 0 && Y > 0 && visited[X - 1][Y - 1] == true && visited[X][Y - 1] == false && visited[X - 1][Y] == false) {
						continue;
					}
					if (X > 0 && Y < 6 && visited[X - 1][Y + 1] == true && visited[X][Y + 1] == false && visited[X - 1][Y] == false) {
						continue;
					}
					if (X < 6 && Y > 0 && visited[X + 1][Y - 1] == true && visited[X][Y - 1] == false && visited[X + 1][Y] == false) {
						continue;
					}
					if (X < 6 && Y < 6 && visited[X + 1][Y + 1] == true && visited[X][Y + 1] == false && visited[X + 1][Y] == false) {
						continue;
					}
					path.push_back(moves_names[i]);
					dfs(X, Y, step + 1);
					path.pop_back();
					visited[X][Y] = false;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	dfs(0, 0, 0);
	int res = 0;
	for (auto x : v) {
		bool ok = true;
		for (int i = 0; i < 48; i++) {
			if (s[i] != '?' && s[i] != x[i]) {
				ok = false;
				break;
			}
		}
		if (ok) res++;
	}
	cout << res << "\n";
	return 0;
}
