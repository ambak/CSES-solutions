#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

string s[1000];
int t[1000];
int n, m;

int f(vector<int> &v) {
	vector<int> l(n);
	vector<int> r(n);
	int res = 0;
	stack<pair<int, int>> q;
	v.push_back(-1);
	for (int i = 0; i <= n; i++) {
		while (!q.empty() && q.top().first > v[i]) {
			r[q.top().second] = i;
			q.pop();
		}
		q.push({v[i], i});
	}
	v.pop_back();
	v.insert(v.begin(), -1);
	q.pop();
	for (int i = n; i >= 0; i--) {
		while (!q.empty() && q.top().first > v[i]) {
			l[q.top().second - 1] = i;
			q.pop();
		}
		q.push({v[i], i});
	}
	v.erase(v.begin());
	for (int i = 0; i < n; i++) {
		res = max(res, v[i] * (r[i] - l[i]));
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		v[i] = m;
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '*') {
				v[i] = j;
				break;
			}
		}
	}
	int res = f(v);
	for (int k = 0; k < n - 1; k++) {
		for (int i = 0; i < n; i++) {
			v[i]--;
			if (v[i] < 0) {
				v[i] = m - k - 1;
				for (int j = k + 1; j < m; j++) {
					if (s[i][j] == '*') {
						v[i] = j - k - 1;
						break;
					}
				}
			}
		}
		res = max(f(v), res);
	}
	cout << res << "\n";
	return 0;
}
