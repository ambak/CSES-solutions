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
		v.push_back({a, b});
	}
	sort(v.begin(), v.end());
	int res = 0;
	int end = INT_MAX;
	for (int i = 0; i < n; i++) {
		if (v[i].second < end) {
			end = v[i].second;
		} else if (end <= v[i].first) {
			res++;
			end = v[i].second;
		}
	}
	cout << res + 1 << "\n";
	return 0;
}
