#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<int> v[200009];
int odw[200009];
int res[200009];

int dfs(int s, int& cycle, int step) {
	odw[s] = step;
	int back = s;
	for (int i : v[s]) {
		if (res[i]) {
			res[s] = res[i] + 1;
			cycle = -1;
			return s;
		}
		if (odw[i]) {
			cycle = i;
			if (v[s][0] == s) cycle = -1;
			res[s] = step - odw[i] + 1;
			return s;
		}
		if (odw[i] == 0) {
			back = dfs(i, cycle, step + 1);
		}
	}
	if (cycle == s) {
		res[s] = res[back];
		cycle = -1;
		return s;
	}
	if (cycle == -1) {
		res[s] = res[back] + 1;
	} else {
		res[s] = res[back];
	}
	return s;
}

void dfs_run(int n) {
	for (int i = 1; i <= n; i++) {
		if (odw[i] == 0) {
			int cycle = 0;
			dfs(i, cycle, 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		v[i].push_back(a);
	}
	dfs_run(n);
	for (int i = 1; i <= n; i++) {
		cout << res[i] << " ";
	}
	return 0;
}
