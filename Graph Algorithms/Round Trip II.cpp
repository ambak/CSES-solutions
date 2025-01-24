#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<int> v[100009];
vector<int> res;
int odw[100009];

bool dfs(int start) {
	odw[start] = 1;
	for (auto e : v[start]) {
		if (odw[e] == 0) {
			if (dfs(e)) {
				if (res[0] == res.back() && res.size() > 1) return true;
				res.push_back(e);
				return true;
			}
		} else if (odw[e] == 1 && e != start) {
			res.push_back(e);
			return true;
		}
		odw[e] = 2;
	}
	return false;
}

void dfs_run(int n) {
	for (int i = 1; i <= n; i++) {
		if (odw[i] == 0) {
			if (dfs(i)) {
				if (res[0] != res.back()) {
					res.push_back(res[0]);
				}
				reverse(res.begin(), res.end());
				cout << res.size() << "\n";
				for (auto r : res) {
					cout << r << " ";
				}
				return;
			}
			odw[i] = 2;
		}
	}
	cout << "IMPOSSIBLE\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}
	dfs_run(n);
	return 0;
}
