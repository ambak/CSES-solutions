#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<int> v[200009];
int t[200009];

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
		t[a]++;
		t[b]++;
	}
	set<int> s;
	for (int i = 1; i <= n; i++) {
		if (t[i] == 1) {
			s.insert(i);
		}
	}
	int res = 0;
	while (!s.empty()) {
		int x = *s.begin();
		s.erase(s.begin());
		t[x]--;
		for (auto it : v[x]) {
			if (t[it] > 0) {
				t[it] = 0;
				for (auto jt : v[it]) {
					t[jt]--;
					if (t[jt] == 1) {
						s.insert(jt);
					}
				}
				res++;
				break;
			}
		}
	}
	cout << res;
	return 0;
}
