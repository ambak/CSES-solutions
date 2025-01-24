#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int t[130];

auto cmp = [](int a, int b) {
	if (t[a] == t[b]) return a < b;
	return t[a] > t[b];
};

void update(int c, set<int, decltype(cmp)> &q, set<int> &w, char &last) {
	q.erase(c);
	if (w.find(c) != w.end()) w.erase(c);
	t[c]--;
	q.insert(c);
	if (t[c]) w.insert(c);
	last = c;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	for (auto c : s) {
		t[int(c)]++;
	}
	int n = s.size();
	int treshold = n / 2;
	if (n % 2) treshold++;

	set<int, decltype(cmp)> q(cmp);
	set<int> w;
	for (int i = 'A'; i <= 'Z'; i++) {
		if (t[i] > treshold) {
			cout << "-1\n";
			return 0;
		}
		q.insert(i);
		if (t[i]) w.insert(i);
	}
	char last = '.';
	for (int i = n; i > 0; i--) {
		int c = *q.begin();
		if (i % 2 && t[c] == treshold) {
			cout << char(c);
			update(c, q, w, last);
		} else {
			int c = *w.begin();
			if (c != last) {
				cout << char(c);
				update(c, q, w, last);
			} else {
				c = *(next(w.begin()));
				cout << char(c);
				update(c, q, w, last);
			}
		}
		if (i % 2) {
			treshold--;
		}
	}
	cout << "\n";
	return 0;
}
