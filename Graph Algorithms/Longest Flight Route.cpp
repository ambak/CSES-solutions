#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<int> v[200009];
vector<int> res;
int in_d[200009];
queue<int> zero_in;
pair<int, int> parent[200009];

void run() {
	while (!zero_in.empty()) {
		auto s = zero_in.front();
		zero_in.pop();
		for (auto x : v[s]) {
			if (x == 1) continue;
			if (parent[x].second < parent[s].second + 1 || (parent[x].second == parent[s].second + 1 && s < parent[x].first)) {
				parent[x] = {s, parent[s].second + 1};
			}
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
		parent[i] = {0, 0};
	}
	zero_in.push(1);
	run();

	int curr = n;
	res.push_back(curr);
	while (parent[curr].first != 0) {
		curr = parent[curr].first;
		res.push_back(curr);
	}
	if (res.size() < 2) {
		cout << "IMPOSSIBLE\n";
	} else {
		reverse(res.begin(), res.end());
		cout << res.size() << "\n";
		for (auto x : res) {
			cout << x << " ";
		}
	}

	return 0;
}
