#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n, m;
vector<int> v[200009];
int odw[200009];
int kol[200009];
queue<int> q;

bool bfs(int start) {
	q.push(start);
	odw[start] = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (auto it : v[x]) {
			if (odw[it] == 0) {
				odw[it] = odw[x] ^ 3;
				q.push(it);
			} else if (odw[it] == odw[x]) {
				return false;
			}
		}
	}
	return true;
}

bool bfs_run() {
	for (int i = 1; i <= n; i++) {
		if (odw[i] == 0) {
			bool ok = bfs(i);
			if (ok == false) {
				return ok;
			}
		}
	}
	return true;
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
	if (bfs_run()) {
		for (int i = 1; i <= n; i++) {
			cout << odw[i] << " ";
		}
		cout << "\n";
	} else {
		cout << "IMPOSSIBLE\n";
	}

	return 0;
}
