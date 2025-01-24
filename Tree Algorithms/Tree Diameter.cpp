#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<int> v[200009];
bool odw[200009];

pair<int, int> dfs(int st, int c) {
	odw[st] = true;
	pair<int, int> res = {st, c};
	for (auto it : v[st]) {
		if (!odw[it]) {
			auto x = dfs(it, c + 1);
			if (res.second < x.second) {
				res = x;
			}
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	auto res = dfs(1, 0);
	for (int i = 1; i <= n; i++) {
		odw[i] = false;
	}
	res = dfs(res.first, 0);
	cout << res.second;
	return 0;
}
