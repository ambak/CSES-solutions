#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Line {
public:
	LL a, b;
	double v;
	Line() {}
	Line(LL a, LL b) : a(a), b(b), v(-DBL_MAX) {}
	bool parallel(const Line &l) const {
		return a == l.a;
	}
	double intersect(const Line &l) const {
		if (parallel(l)) return DBL_MAX;
		return double(l.b - b) / (a - l.a);
	}
	bool operator<(const Line &l) const {
		if (l.b != LONG_LONG_MAX)
			return a > l.a;
		return v < l.a;
	}
};

class CHT {
public:
	void add(Line &l) {
		set<Line>::iterator it = hull.lower_bound(l);
		if (it != hull.end() && l.parallel(*it)) {
			if (it->b > l.b) {
				hull.erase(it);
			} else {
				return;
			}
		}
		hull.insert(l);
		it = hull.find(l);
		if (bad(it)) {
			hull.erase(it);
			return;
		}
		while (it != hull.begin() && bad(prev(it))) {
			hull.erase(prev(it));
		}
		while (next(it) != hull.end() && bad(next(it))) {
			hull.erase(next(it));
		}
		update(it);
		if (it != hull.begin()) update(prev(it));
		if (next(it) != hull.end()) update(next(it));
	}
	Line query(LL x) {
		Line l1;
		l1.a = x;
		l1.b = LONG_LONG_MAX;
		l1.v = x;
		auto it = --hull.lower_bound(l1);
		return *it;
	}

private:
	set<Line>::iterator update(set<Line>::iterator it) {
		if (it == hull.begin()) return it;
		auto v = it->intersect(*prev(it));
		Line l1 = *it;
		hull.erase(it);
		l1.v = v;
		hull.insert(l1);
		return hull.find(l1);
	}
	bool bad(set<Line>::iterator it) {
		Line l1, l2, l3;
		if (it != hull.begin() && next(it) != hull.end()) {
			l1 = *prev(it);
			l2 = *it;
			l3 = *next(it);
			return l1.intersect(l3) <= l1.intersect(l2);
		}
		return false;
	}
	set<Line> hull;
};

LL s[200009];
LL f[200009];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	LL n, x;
	cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> f[i];
	}
	CHT cht;
	Line st = Line(x, 0);
	cht.add(st);
	for (int i = 1; i < n; i++) {
		Line l = cht.query(s[i]);
		l.b += l.a * s[i];
		l.a = f[i];
		cht.add(l);
	}
	Line l = cht.query(s[n]);
	cout << l.b + l.a * s[n] << "\n";
	return 0;
}
