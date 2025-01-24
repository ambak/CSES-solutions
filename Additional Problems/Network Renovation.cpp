#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<int> v[100009];
bool odw[100009];
vector<int> leaves;

void dfs(int st) {
	odw[st] = true;
	if (v[st].size() == 1) {
		leaves.push_back(st);
	}
	for (auto x : v[st]) {
		if (odw[x] == false) {
			dfs(x);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);
	int d = (leaves.size() + 1) / 2;
	cout << d << "\n";
	for (int i = 0; i < d; i++) {
		cout << leaves[i] << " " << leaves[(i + d) % leaves.size()] << "\n";
	}
	return 0;
}
