#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<int> v[100009];
int outdegree[100009];
priority_queue<int> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[b].push_back(a);
		outdegree[a]++;
	}

	for (int i = 1; i <= n; i++) {
		if (outdegree[i] == 0) {
			pq.push(i);
		}
	}
	vector<int> res;
	while (!pq.empty()) {
		int b = pq.top();
		pq.pop();
		res.push_back(b);

		for (auto a : v[b]) {
			outdegree[a]--;
			if (outdegree[a] == 0) {
				pq.push(a);
			}
		}
	}
	reverse(res.begin(), res.end());
	for (auto b : res) cout << b << " ";
	return 0;
}
