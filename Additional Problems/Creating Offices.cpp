#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<int> v[200009];
vector<int> w[200009];
int dist[200009];
int t[200009];
int tt[200009];
vector<int> order, res;
int n, d, c = 1;

void set_depth() {
	vector<bool> odw(n);
	queue<int> q;
	q.push(0);
	odw[0] = true;
	while (!q.empty()) {
		int st = q.front();
		q.pop();
		order.push_back(t[st]);
		for (auto x : v[st]) {
			if (!odw[x]) {
				t[x] = c;
				tt[c] = x;
				c++;
				q.push(x);
				odw[x] = true;
				w[t[x]].push_back(t[st]);
				w[t[st]].push_back(t[x]);
			}
		}
	}
	reverse(order.begin(), order.end());
}

void bfs(int st) {
	queue<int> q;
	q.push(st);
	dist[st] = d;
	while (!q.empty()) {
		st = q.front();
		q.pop();
		for (auto x : w[st]) {
			if (dist[x] < dist[st] - 1) {
				dist[x] = dist[st] - 1;
				q.push(x);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> d;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	set_depth();
	for (auto o : order) {
		if (dist[o] == 0) {
			res.push_back(o);
			bfs(o);
		}
	}
	cout << int(res.size()) << "\n";
	for (auto x : res) {
		cout << tt[x] + 1 << " ";
	}
	cout << "\n";
	return 0;
}
