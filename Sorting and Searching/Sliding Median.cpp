#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int d[200009];

multiset<int> l;
multiset<int> r;

int main() {
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> d[i];
	}
	vector<int> v;
	for (int i = 0; i < k; i++) {
		v.push_back(d[i]);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < k / 2 + k % 2; i++) {
		l.insert(v[i]);
	}
	for (int i = k / 2 + k % 2; i < k; i++) {
		r.insert(v[i]);
	}
	int x = *l.rbegin();
	l.erase(l.find(x));
	cout << x << " ";
	for (int i = k; i < n; i++) {
		if (l.find(d[i - k]) != l.end()) {
			l.erase(l.find(d[i - k]));
			l.insert(x);
		} else if (r.find(d[i - k]) != r.end()) {
			r.erase(r.find(d[i - k]));
			r.insert(x);
		}

		if (d[i] > *r.begin()) {
			r.insert(d[i]);
			x = *r.begin();
			r.erase(r.begin());
		} else {
			l.insert(d[i]);
			x = *l.rbegin();
			l.erase(l.find(x));
		}
		cout << x << " ";
	}
	cout << "\n";
	return 0;
}
