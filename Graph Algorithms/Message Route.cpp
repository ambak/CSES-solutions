#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n, m;
vector<int> v[100009];
int odw[100009];
int kol[100009];
queue<int> q;
vector<int> res;

bool bfs() {
	q.push(1);
	odw[1] = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (x == n) {
			while (x != 0) {
				res.push_back(x);
				x = kol[x];
			}
			reverse(res.begin(), res.end());
			return true;
		}
		for (unsigned i = 0; i < v[x].size(); i++) {
			if (!odw[v[x][i]]) {
				odw[v[x][i]] = odw[x] + 1;
				kol[v[x][i]] = x;
				q.push(v[x][i]);
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	if (bfs()) {
		cout << odw[n] << "\n";
		for (int x : res) {
			cout << x << " ";
		}
		cout << "\n";
	} else {
		cout << "IMPOSSIBLE\n";
	}

	return 0;
}
