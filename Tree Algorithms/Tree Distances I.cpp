#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<int> v[200009];
bool odw[200009];
int t[200009];

void clean_odw(int n) {
	for (int i = 1; i <= n; i++) {
		odw[i] = false;
	}
}

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

void dfs2(int st, int c) {
	odw[st] = true;
	t[st] = max(t[st], c);
	for (auto it : v[st]) {
		if (!odw[it]) {
			dfs2(it, c + 1);
		}
	}
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
	clean_odw(n);
	auto res2 = dfs(res.first, 0);
	clean_odw(n);
	dfs2(res.first, 0);
	clean_odw(n);
	dfs2(res2.first, 0);
	for (int i = 1; i <= n; i++) {
		cout << t[i] << " ";
	}
	return 0;
}
