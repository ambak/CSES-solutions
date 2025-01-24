#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<int> v[100009];
vector<int> ans[100009];
int odw[100009];
int outdegree[100009];

void dfs(int st, int parent, int level) {
	odw[st] = level;
	for (auto x : v[st]) {
		if (odw[x] == 0) {
			dfs(x, st, level + 1);
		} else if (x != parent && odw[x] < level) {
			outdegree[x]++;
			ans[x].push_back(st);
		}
	}
	if (outdegree[st] % 2 && parent != 0) {
		outdegree[st]++;
		ans[st].push_back(parent);
	} else if (outdegree[st] % 2 == 0 && parent != 0) {
		outdegree[parent]++;
		ans[parent].push_back(st);
	}
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
	for (int i = 1; i <= n; i++) {
		if (odw[i] == false) {
			dfs(i, 0, 1);
		}
		if (outdegree[i] % 2) {
			cout << "IMPOSSIBLE\n";
			return 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (auto x : ans[i]) {
			cout << i << " " << x << "\n";
		}
	}
	return 0;
}
