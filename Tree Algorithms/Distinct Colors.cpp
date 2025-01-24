#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<int> v[200009];
int t[200009];
int d[200009];
set<int> s[200009];
bool odw[200009];

void dfs(int st) {
	odw[st] = true;
	for (int it : v[st]) {
		if (odw[it]) {
			continue;
		}
		dfs(it);
		if (s[it].size() > s[st].size()) {
			swap(s[it], s[st]);
		}
		for (auto jt : s[it]) {
			s[st].insert(jt);
		}
		s[it].clear();
	}
	s[st].insert(d[st]);
	t[st] = s[st].size();
}

int main() {
	ios_base::sync_with_stdio(false);
	LL n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> d[i];
	}
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);
	for (int i = 1; i <= n; i++) {
		cout << t[i] << " ";
	}
	return 0;
}
