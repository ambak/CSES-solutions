#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n;

void f(int x, multiset<int> &ms, set<int> &zeros, set<int> &ones, int mode) {
	auto itl = ones.lower_bound(x);
	int l = -1;
	if (itl != ones.begin()) {
		itl = prev(itl);
		l = *itl;
	}
	if (x - l > 1) {
		if (mode == 1) ms.insert(x - l - 1);
		if (mode == 2) ms.erase(ms.find(x - l - 1));
	}
	auto itr = ones.upper_bound(x);
	int r = n;
	if (itr != ones.end()) {
		r = *itr;
	}
	if (r - x > 1) {
		if (mode == 1) ms.insert(r - x - 1);
		if (mode == 2) ms.erase(ms.find(r - x - 1));
	}
	if (mode == 1) ms.erase(ms.find(r - l - 1));
	if (mode == 2) ms.insert(r - l - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	int m;
	cin >> s >> m;
	n = s.size();
	multiset<int> ms;
	set<int> zeros, ones;
	int pr = s[0];
	int id = 0;
	s.push_back('#');
	for (int i = 1; i <= n; i++) {
		if (s[i] != pr) {
			ms.insert(i - id);
			pr = s[i];
			id = i;
		}
	}
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') zeros.insert(i);
		if (s[i] == '1') ones.insert(i);
	}
	while (m--) {
		int x;
		cin >> x;
		x--;
		if (s[x] == '0') {
			s[x] = '1';
			f(x, ms, ones, zeros, 2);
			f(x, ms, zeros, ones, 1);
			ones.insert(x);
			zeros.erase(x);
		} else if (s[x] == '1') {
			s[x] = '0';
			f(x, ms, zeros, ones, 2);
			f(x, ms, ones, zeros, 1);
			zeros.insert(x);
			ones.erase(x);
		}
		cout << *ms.rbegin() << " ";
	}
	return 0;
}
