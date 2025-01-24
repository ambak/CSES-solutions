#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<LL> v[200009];
bool odw[200009];
LL t[200009];
pair<LL, LL> d[200009];

void clean_odw(LL n) {
	for (LL i = 1; i <= n; i++) {
		odw[i] = false;
	}
}

pair<LL, LL> dfs(LL st) {
	odw[st] = true;
	pair<LL, LL> res = {1, 1};
	for (auto it : v[st]) {
		if (!odw[it]) {
			auto x = dfs(it);
			res.second += x.second;
			res.first += x.second + x.first;
		}
	}
	d[st] = res;
	return res;
}

void dfs2(LL st, LL c, LL n) {
	odw[st] = true;
	for (auto it : v[st]) {
		if (!odw[it]) {
			t[it] = c - 2 * d[it].second;
			LL c2 = t[it] + n;
			dfs2(it, c2, n);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	LL n;
	cin >> n;
	for (LL i = 1; i < n; i++) {
		LL a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	auto res = dfs(1);
	clean_odw(n);
	dfs2(1, res.first, n);
	t[1] = d[1].first - d[1].second;
	for (LL i = 1; i <= n; i++) {
		cout << t[i] << " ";
	}
	return 0;
}
