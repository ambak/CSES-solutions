#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<int> v;
stack<pair<int, int> > s;

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	for (int i = 0; i < n; i++) {
		while (!s.empty() && s.top().first >= v[i]) {
			s.pop();
		}
		if (s.empty()) {
			cout << 0 << " ";
			s.push({v[i], i + 1});
		} else {
			cout << s.top().second << " ";
			s.push({v[i], i + 1});
		}
	}

	return 0;
}
