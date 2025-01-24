#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct Line {
	int x1, y1, x2, y2;
	bool operator<(Line &l) {
		if (x1 != l.x1) return x1 < l.x1;
		if (x2 != l.x2) return x2 < l.x2;
		if (y1 != l.y1) return y1 < l.y1;
		return y2 < l.y2;
	}
};

const int M = 1 << 21;
LL t[M];

void update(int x, LL v) {
	for (; x < M; x += x & -x) {
		t[x] += v;
	}
}

LL query(int x) {
	LL res = 0;
	for (; x > 0; x -= x & -x) {
		res += t[x];
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<Line> horizontal;
	vector<Line> vertical;

	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		y1 += 1e6 + 2;
		y2 += 1e6 + 2;
		if (x1 == x2) {
			if (y1 < y2) {
				vertical.push_back({x1, y1, x2, y2});
			} else {
				vertical.push_back({x2, y2, x1, y1});
			}
		} else {
			if (x1 < x2) {
				horizontal.push_back({x1, y1, x2, y2});
			} else {
				horizontal.push_back({x2, y2, x1, y1});
			}
		}
	}

	sort(horizontal.begin(), horizontal.end());
	sort(vertical.begin(), vertical.end());

	unsigned h = 0, v = 0;
	LL res = 0;
	set<pair<int, int>> q;
	while (v != vertical.size()) {
		if (!q.empty() && q.begin()->first < vertical[v].x1) {
			update(q.begin()->second, -1);
			q.erase(q.begin());
		} else if (h == horizontal.size() || horizontal[h].x1 > vertical[v].x1) {
			res += query(vertical[v].y2) - query(vertical[v].y1 - 1);
			v++;
		} else if (h != horizontal.size()) {
			update(horizontal[h].y1, 1);
			q.insert({horizontal[h].x2, horizontal[h].y1});
			h++;
		}
	}
	cout << res << "\n";
	return 0;
}
