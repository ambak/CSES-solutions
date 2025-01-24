#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<int> v[200009];
int in_d[200009];
queue<int> zero_in;
LL parent[200009];
const int MOD = 1e9 + 7;

void run() {
	while (!zero_in.empty()) {
		auto s = zero_in.front();
		zero_in.pop();
		for (auto x : v[s]) {
			if (x == 1) continue;
			parent[x] += parent[s];
			parent[x] %= MOD;
			in_d[x]--;
			if (in_d[x] == 0) {
				zero_in.push(x);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		in_d[b]++;
	}
	for (int i = 2; i < n; i++) {
		if (in_d[i] == 0) {
			zero_in.push(i);
		}
	}
	run();
	for (int i = 1; i <= n; i++) {
		parent[i] = 0;
	}
	parent[1] = 1;
	zero_in.push(1);
	run();
	cout << parent[n] << "\n";

	return 0;
}
