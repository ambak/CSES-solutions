#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

map<vector<int>, int> m;
int id;

int tree_encode(int st, int parent, vector<vector<int>> &v) {
	vector<int> children;
	for (auto x : v[st]) {
		if (x != parent)
			children.push_back(tree_encode(x, st, v));
	}
	sort(children.begin(), children.end());
	if (m.find(children) == m.end()) m[children] = ++id;
	return m[children];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<vector<int>> t1(n + 1);
		vector<vector<int>> t2(n + 1);
		for (int i = 1; i < n; i++) {
			int a, b;
			cin >> a >> b;
			t1[a].push_back(b);
			t1[b].push_back(a);
		}
		for (int i = 1; i < n; i++) {
			int a, b;
			cin >> a >> b;
			t2[a].push_back(b);
			t2[b].push_back(a);
		}
		int ans1 = tree_encode(1, -1, t1);
		int ans2 = tree_encode(1, -1, t2);
		if (ans1 == ans2) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
		id = 0;
		m.clear();
	}
	return 0;
}
