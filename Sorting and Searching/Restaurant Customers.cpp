#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<pair<int, int> > v;

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({a, 1});
		v.push_back({b, -1});
	}
	sort(v.begin(), v.end());
	int current = 0;
	int maximum = 0;
	for (int i = 0; i < n << 1; i++) {
		current += v[i].second;
		maximum = max(maximum, current);
	}
	cout << maximum << "\n";
	return 0;
}
