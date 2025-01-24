#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

pair<int, int> low[100009];
vector<int> v[100009];
bool res[100009];

void dfs(int st, int &C, int parent) {
	low[st] = {C, C};
	int cnt = 0;
	for (auto x : v[st]) {
		if (x == parent) {
			continue;
		}
		if (low[x].first == 0) {
			C++;
			cnt++;
			dfs(x, C, st);
			if (st != 1 && low[x].second >= low[st].first) {
				res[st] = true;
			}
			low[st].second = min(low[st].second, low[x].second);
		} else {
			low[st].second = min(low[st].second, low[x].first);
		}
	}
	if (st == 1 && cnt > 1) res[st] = true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int C = 1;
	dfs(1, C, 0);
	int cnt = 0;
	for (int i = 1; i <= n; i++) cnt += res[i];
	cout << cnt << "\n";
	for (int i = 1; i <= n; i++)
		if (res[i]) cout << i << " ";
	cout << "\n";
	return 0;
}
