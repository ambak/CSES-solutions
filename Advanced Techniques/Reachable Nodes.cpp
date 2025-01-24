#include <bits/stdc++.h>
#pragma GCC target("popcnt")
using namespace std;
typedef long long LL;

const int M = 50001;
bitset<M> bit[M];
vector<int> v[M];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> indegree(M);
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		v[b].push_back(a);
		indegree[a]++;
	}
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		bit[i][i] = 1;
		if (indegree[i] == 0) q.push(i);
	}
	while (!q.empty()) {
		int w = q.front();
		q.pop();
		for (auto x : v[w]) {
			indegree[x]--;
			if (indegree[x] == 0) q.push(x);
			bit[x] |= bit[w];
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << bit[i].count() << " ";
	}
	return 0;
}
