#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<LL> v[200009];
int odw[200009];
int d[200009][20];
LL in[200009];
LL out[200009];
int indegree[200009];
LL res[200009];
int parent[200009];

void dfs(int st, int c) {
	odw[st] = c;
	for (auto it : v[st]) {
		if (odw[it] == 0) {
			d[it][1] = st;
			for (int i = 2; i < 20; i++) {
				d[it][i] = d[d[it][i - 1]][i - 1];
			}
			parent[it] = st;
			dfs(it, c + 1);
		}
	}
}

int query(int a, int b) {
	if (odw[a] < odw[b]) {
		swap(a, b);
	}
	int k = odw[a] - odw[b];
	int id = 1;
	while (k) {
		if (k & 1) {
			a = d[a][id];
		}
		k /= 2;
		id++;
	}
	if (a == b) {
		return a;
	}
	for (int i = 19; i > 0; i--) {
		if (d[a][i] != d[b][i]) {
			a = d[a][i];
			b = d[b][i];
		}
	}
	return d[a][1];
}

int main() {
	ios_base::sync_with_stdio(false);
	LL n, m;
	cin >> n >> m;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
		indegree[a]++;
		indegree[b]++;
	}
	if (n == 1) {
		cout << m;
		return 0;
	}
	dfs(1, 1);
	while (m--) {
		int a, b;
		cin >> a >> b;
		int x = query(a, b);
		if (x != a && x != b) {
			in[a]++;
			in[b]++;
			out[x] += 2;
			res[x]--;
		} else if (x == a) {
			in[b]++;
			out[x]++;
		} else {
			in[a]++;
			out[x]++;
		}
	}
	set<int> s;
	for (int i = 2; i <= n; i++) {
		if (indegree[i] == 1) {
			s.insert(i);
		}
	}
	while (!s.empty()) {
		int x = *s.begin();
		s.erase(s.begin());
		if (x == 1) continue;
		res[x] += in[x];
		in[parent[x]] += in[x] - out[x];
		indegree[parent[x]]--;
		if (indegree[parent[x]] == 1) {
			s.insert(parent[x]);
		}
	}
	res[1] += in[1];
	for (int i = 1; i <= n; i++) {
		cout << res[i] << " ";
	}
	return 0;
}
