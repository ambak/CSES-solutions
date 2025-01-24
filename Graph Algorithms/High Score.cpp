#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<pair<LL, LL> > v[2505];
vector<LL> v2[2505];
LL d[2505];
LL dd[2505];
bool odw[2505];
bool odw2[2505];
int n, m;

void bfs(int w) {
	queue<LL> q;
	q.push(w);
	odw2[w] = true;
	while (!q.empty()) {
		LL x = q.front();
		q.pop();
		for (auto it : v2[x]) {
			if (odw2[it] == false) {
				odw2[it] = true;
				q.push(it);
			}
		}
	}
	q.push(1);
	odw[1] = true;
	while (!q.empty()) {
		LL x = q.front();
		q.pop();
		for (auto it : v[x]) {
			if (odw[it.first] == false) {
				odw[it.first] = true;
				q.push(it.first);
			}
		}
	}
}

bool bellman_ford(int w) {
	for (int i = 0; i <= n; i++) d[i] = LONG_LONG_MIN;
	d[w] = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= n; j++)
			for (auto it = v[j].begin(); it != v[j].end(); ++it)
				if (d[j] > LONG_LONG_MIN && d[it->first] < d[j] + it->second)
					d[it->first] = d[j] + it->second;

	for (int i = 0; i <= n; i++) dd[i] = d[i];

	for (int i = 0; i < n; i++)
		for (int j = 0; j <= n; j++)
			for (auto it = v[j].begin(); it != v[j].end(); ++it)
				if (d[j] > LONG_LONG_MIN && d[it->first] < d[j] + it->second)
					d[it->first] = d[j] + it->second;

	bfs(n);
	for (int i = 0; i <= n; i++) {
		if (d[i] != dd[i] && odw[i] && odw2[i])
			return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b, d;
		cin >> a >> b >> d;
		v[a].push_back({b, d});
		v2[b].push_back(a);
	}

	if (!bellman_ford(1)) {
		cout << "-1\n";
	} else {
		cout << d[n] << "\n";
	}
	return 0;
}
