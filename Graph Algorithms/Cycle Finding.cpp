#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<tuple<LL, LL, LL> > edges;
LL odl[5005];
LL pr[5005];
int n, m;

void bellman_ford() {
	for (int i = 0; i <= n; i++) odl[i] = INT_MAX;
	for (int i = 0; i <= n; i++) {
		for (auto e : edges) {
			auto& [a, b, c] = e;
			if (odl[b] > odl[a] + c) {
				odl[b] = odl[a] + c;
				pr[b] = a;
			}
		}
	}
	bool n_cycle = false;
	LL start;
	for (auto e : edges) {
		auto& [a, b, c] = e;
		if (odl[b] > odl[a] + c) {
			n_cycle = true;
			start = b;
			break;
		}
	}
	if (n_cycle) {
		cout << "YES\n";
		vector<LL> res;
		set<LL> s;
		LL x = start;
		do {
			res.push_back(x);
			s.insert(x);
			x = pr[x];
		} while (s.find(x) == s.end());
		res.push_back(x);
		reverse(res.begin(), res.end());
		for (unsigned i = 0; i < res.size(); i++) {
			cout << res[i] << " ";
			if (i > 0 && res[i] == res[0]) {
				break;
			}
		}
	} else {
		cout << "NO\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		LL a, b, c;
		cin >> a >> b >> c;
		edges.push_back(make_tuple(a, b, c));
	}
	bellman_ford();
	return 0;
}
