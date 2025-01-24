#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

set<string> v;

void permute(string s, int l, int r) {
	if (l == r) {
		v.insert(s);
	} else {
		for (int i = l; i <= r; i++) {
			swap(s[i], s[l]);
			permute(s, l + 1, r);
			swap(s[i], s[l]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	permute(s, 0, s.size() - 1);
	cout << v.size() << "\n";
	for (auto s : v) {
		cout << s << "\n";
	}
	return 0;
}
