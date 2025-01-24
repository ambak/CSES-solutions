#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n, m;
vector<int> v[100009];
bool odw[100009];

void dfs(int start) {
	odw[start] = true;
	for (unsigned i = 0; i < v[start].size(); i++) {
		if (!odw[v[start][i]]) {
			dfs(v[start][i]);
		}
	}
}

void dfs_run() {
	int res = 0;
	dfs(1);
	vector<int> answer;
	for (int i = 2; i <= n; i++) {
		if (odw[i] == false) {
			res++;
			answer.push_back(i);
			dfs(i);
		}
	}
	cout << res << "\n";
	for (int it : answer) {
		cout << "1 " << it << "\n";
	}
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
	dfs_run();
	return 0;
}
