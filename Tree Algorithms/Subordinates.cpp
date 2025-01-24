#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<int> v[200009];
int t[200009];
bool odw[200009];

int dfs(int st) {
	odw[st] = true;
	int res = 0;
	for (auto it : v[st]) {
		if (!odw[it]) {
			res += dfs(it);
		}
	}
	t[st] = res;
	return res + 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		int x;
		cin >> x;
		v[x].push_back(i);
	}
	dfs(1);
	for (int i = 1; i <= n; i++) {
		cout << t[i] << " ";
	}
	return 0;
}
