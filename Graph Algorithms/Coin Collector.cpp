#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n, m;

int coins[100009];
vector<int> v[100009];
vector<int> v2[100009];

vector<int> order;
bool odw1[200009];
void dfs1(int st) {
	odw1[st] = true;
	for (auto x : v[st]) {
		if (odw1[x] == false) {
			dfs1(x);
		}
	}
	order.push_back(st);
}

int odw2[200009];
void dfs2(int st, int c) {
	odw2[st] = c;
	for (auto x : v2[st]) {
		if (odw2[x] == -1) {
			dfs2(x, c);
		}
	}
}

void solve() {
	for (int i = 0; i < n; i++) {
		if (odw1[i] == false) {
			dfs1(i);
		}
	}
	reverse(order.begin(), order.end());
	int c = 0;
	fill(odw2, odw2 + n, -1);
	for (auto x : order) {
		if (odw2[x] == -1) {
			dfs2(x, c);
			c++;
		}
	}
	vector<int> indegree(c);
	vector<vector<int>> vv(c);
	for (int i = 0; i < n; i++) {
		for (int x : v2[i]) {
			if (odw2[x] != odw2[i]) {
				vv[odw2[i]].push_back(odw2[x]);
				indegree[odw2[x]]++;
			}
		}
	}
	vector<LL> sum(c);
	for (int i = 0; i < n; i++) {
		sum[odw2[i]] += coins[i];
	}
	vector<int> q;
	for (unsigned i = 0; i < indegree.size(); i++) {
		if (indegree[i] == 0) {
			q.push_back(i);
		}
	}
	vector<vector<LL>> max_input(c);
	while (!q.empty()) {
		int x = q.back();
		q.pop_back();
		LL maxi = 0;
		for (auto c : max_input[x]) {
			maxi = max(maxi, c);
		}
		sum[x] += maxi;
		for (int i : vv[x]) {
			max_input[i].push_back(sum[x]);
			indegree[i]--;
			if (indegree[i] == 0) {
				q.push_back(i);
			}
		}
	}
	LL res = 0;
	for (auto s : sum) {
		res = max(res, s);
	}
	cout << res << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		v[a].push_back(b);
		v2[b].push_back(a);
	}
	solve();
	return 0;
}
