#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n, m;

int neg(int a) {
	if (a > n) return a - n;
	return a + n;
}

vector<int> v[200009];
vector<int> v2[200009];

vector<int> order;
bool odw1[200009];
void dfs1(int st) {
	odw1[st] = true;
	for (auto x : v[st]) {
		if (odw1[x] == false) {
			dfs1(x);
		}
	}
	order.push_back(st);
}

int odw2[200009];
bool dfs2(int st, int c) {
	odw2[st] = c;
	if (odw2[neg(st)] == c) return false;
	int res = true;
	for (auto x : v2[st]) {
		if (odw2[x] == 0) {
			res = dfs2(x, c);
		}
	}
	return res;
}

void solve_2sat() {
	for (int i = 1; i <= 2 * n; i++) {
		if (odw1[i] == false) {
			dfs1(i);
		}
	}
	reverse(order.begin(), order.end());
	int c = 0;
	bool exist = true;
	for (auto x : order) {
		if (odw2[x] == false) {
			c++;
			if (dfs2(x, c) == false) {
				exist = false;
				break;
			}
		}
	}
	if (exist == false) {
		cout << "IMPOSSIBLE\n";
		return;
	}
	vector<char> res;
	for (int i = 1; i <= n; i++) {
		if (odw2[i] > odw2[neg(i)]) {
			res.push_back('+');
		} else {
			res.push_back('-');
		}
	}
	for (auto x : res) {
		cout << x << " ";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		char A, B;
		int a, b;
		cin >> A >> a >> B >> b;
		if (A == '-') {
			a = neg(a);
		}
		if (B == '-') {
			b = neg(b);
		}
		v[neg(a)].push_back(b);
		v[neg(b)].push_back(a);
		v2[b].push_back(neg(a));
		v2[a].push_back(neg(b));
	}
	solve_2sat();
	return 0;
}
