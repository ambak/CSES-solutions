#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n;
vector<int> v[1 << 15];
vector<int> res;
bool odw[1 << 15];

void dfs(int st) {
	odw[st] = true;
	for (int x : v[st]) {
		if (odw[x] == false) {
			res.push_back(x & 1);
			dfs(x);
		}
	}
	if (int(res.size()) == (1 << n) - 1) return;
	odw[st] = false;
	res.pop_back();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < 1 << n; i++) {
		v[i].push_back(((i << 1) + 1) & ((1 << n) - 1));
		v[i].push_back((i << 1) & ((1 << n) - 1));
	}
	dfs(0);
	for (int i = 0; i < n; i++) cout << "0";
	for (int x : res) cout << x;
	return 0;
}
