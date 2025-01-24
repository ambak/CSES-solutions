#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int odl[32][200009];
int pos[200009];
pair<int, int> odw[200009];
pair<int, int> in_cycyle[200009];
vector<int> v[200009];

int dfs(int st) {
	if (pos[st] != 0 || in_cycyle[st].first != 0) {
		return pos[st] + 1;
	}
	int x = v[st][0];
	pos[st] = dfs(x);
	return pos[st] + 1;
}

void dfs_start(int n) {
	for (int i = 1; i <= n; i++) {
		dfs(i);
	}
}

int find_cycle(int st, int c, int id, int j) {
	odw[st] = {id + 1, j};
	int x = v[st][0];
	int res = 0;
	if (odw[x].first == false) {
		res = find_cycle(x, c, id, j);
	} else if (odw[x].second != j) {
		return -1;
	} else {
		if (in_cycyle[x].first != 0) {
			return c - 1;
		}
		in_cycyle[x].first = c;
		in_cycyle[x].second = id;
		res = find_cycle(x, c + 1, id, j);
	}
	return res;
}

vector<int> find_all_cycles(int n) {
	vector<int> res;
	for (int i = 1; i <= n; i++) {
		if (odw[i].first == 0) {
			int r = find_cycle(i, 1, res.size(), i);
			if (r != -1) {
				res.push_back(r);
			}
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> odl[1][i];
		v[i].push_back(odl[1][i]);
	}
	for (int j = 2; j < 32; j++) {
		for (int i = 1; i <= n; i++) {
			odl[j][i] = odl[j - 1][odl[j - 1][i]];
		}
	}
	vector<int> cycle_count = find_all_cycles(n);
	dfs_start(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if (in_cycyle[a].first != 0 && in_cycyle[b].first == 0) {
			cout << "-1\n";
		} else if (in_cycyle[a].first != 0 && in_cycyle[b].first != 0 && in_cycyle[a].second != in_cycyle[b].second) {
			cout << "-1\n";
		} else if (in_cycyle[a].first != 0 && in_cycyle[b].first != 0 && in_cycyle[a].second == in_cycyle[b].second) {
			if (in_cycyle[a].first <= in_cycyle[b].first) {
				cout << in_cycyle[b].first - in_cycyle[a].first << "\n";
			} else {
				cout << in_cycyle[b].first - in_cycyle[a].first + cycle_count[in_cycyle[a].second] << "\n";
			}
		} else if (in_cycyle[a].first == 0 && in_cycyle[b].first != 0) {
			int res = pos[a];
			int j = 1, k = pos[a];
			while (k) {
				if (k & 1) {
					a = odl[j][a];
				}
				j++;
				k >>= 1;
			}
			if (in_cycyle[a].first != 0 && in_cycyle[b].first != 0 && in_cycyle[a].second == in_cycyle[b].second) {
				if (in_cycyle[a].first <= in_cycyle[b].first) {
					cout << res + in_cycyle[b].first - in_cycyle[a].first << "\n";
				} else {
					cout << res + in_cycyle[b].first - in_cycyle[a].first + cycle_count[in_cycyle[a].second] << "\n";
				}
			} else {
				cout << "-1\n";
			}
		} else {
			if (pos[a] == pos[b] && a == b) {
				cout << "0\n";
				continue;
			}
			if ((pos[a] == pos[b] && a != b) || pos[a] < pos[b]) {
				cout << "-1\n";
				continue;
			}
			int res = pos[a] - pos[b];
			int j = 1, k = res;
			while (k) {
				if (k & 1) {
					a = odl[j][a];
				}
				j++;
				k >>= 1;
			}
			if (a == b) {
				cout << res << "\n";
			} else {
				cout << "-1\n";
			}
		}
	}

	return 0;
}
