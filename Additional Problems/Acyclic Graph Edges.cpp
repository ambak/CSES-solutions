#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<int> v[100009];
int odw[100009];
vector<pair<int, int>> res;

int bfs(int st, int C) {
	queue<int> q;
	q.push(st);
	odw[st] = C;
	C++;
	while (!q.empty()) {
		int z = q.front();
		q.pop();
		for (auto x : v[z]) {
			if (odw[x] == 0) {
				odw[x] = C;
				C++;
				q.push(x);
			}
			if (odw[x] > odw[z]) {
				res.emplace_back(z, x);
			}
		}
	}
	return C;
}

int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int C = 1;
	for (int i = 1; i <= n; i++) {
		if (odw[i] == 0)
			C = bfs(i, C);
	}
	for (auto [a, b] : res) {
		cout << a << " " << b << "\n";
	}
	return 0;
}
