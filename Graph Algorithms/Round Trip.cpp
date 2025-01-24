#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n, m;
vector<int> v[100009];
int odw[100009];
vector<int> answer;
bool print;

void dfs(int start, int length) {
	odw[start] = length;
	for (unsigned i = 0; i < v[start].size(); i++) {
		if (print) {
			break;
		}
		if (odw[v[start][i]] != 0 && length - odw[v[start][i]] >= 2) {
			print = true;
			answer.push_back(v[start][i]);
			break;
		}
		if (!odw[v[start][i]]) {
			dfs(v[start][i], length + 1);
		}
	}
	if (answer.size() > 1 && answer[0] == answer[answer.size() - 1]) {
		return;
	}
	if (print) {
		answer.push_back(start);
		return;
	}
}

void dfs_run() {
	dfs(1, 1);
	for (int i = 2; i <= n; i++) {
		if (odw[i] == 0 && answer.size() == 0) {
			dfs(i, 1);
		}
	}
	if (!answer.size()) {
		cout << "IMPOSSIBLE\n";
	} else {
		cout << answer.size() << "\n";
		for (int it : answer) {
			cout << it << " ";
		}
		cout << "\n";
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
