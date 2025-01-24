#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int M = 1 << 21;

struct SegTree {
	LL v, min, mincnt;
} t[2 * M + 5];

void init(int st, int b, int e) {
	if (b == e) {
		t[st].mincnt = 1;
		return;
	} else {
		int mid = (b + e) / 2;
		init(st * 2, b, mid);
		init(st * 2 + 1, mid + 1, e);
	}
	t[st].mincnt += t[st * 2].mincnt + t[st * 2 + 1].mincnt;
}

void update(int b, int e, int B, int E, LL val, int st) {
	if (b <= B && e >= E) {
		t[st].v += val;
		t[st].min += val;
		return;
	} else {
		t[st * 2].v += t[st].v;
		t[st * 2 + 1].v += t[st].v;
		t[st * 2].min += t[st].v;
		t[st * 2 + 1].min += t[st].v;
		t[st].v = 0;
		const int MID = (B + E) / 2;
		if (b <= MID) update(b, e, B, MID, val, st * 2);
		if (e > MID) update(b, e, MID + 1, E, val, st * 2 + 1);
	}

	if (t[st * 2].min == t[st * 2 + 1].min) {
		t[st].min = t[st * 2].min;
		t[st].mincnt = t[st * 2].mincnt + t[st * 2 + 1].mincnt;
	} else {
		if (t[st * 2].min < t[st * 2 + 1].min) {
			t[st].min = t[st * 2].min;
			t[st].mincnt = t[st * 2].mincnt;
		} else {
			t[st].min = t[st * 2 + 1].min;
			t[st].mincnt = t[st * 2 + 1].mincnt;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	const LL dim = 2 * 1e6 + 2;
	int n;
	cin >> n;
	init(1, 1, dim);
	vector<pair<int, pair<int, int> > > add, rem;
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1 += dim / 2, y1 += dim / 2, x2 += dim / 2, y2 += dim / 2;
		add.push_back({x1, {y1 + 1, y2}});
		rem.push_back({x2, {y1 + 1, y2}});
	}
	sort(add.begin(), add.end());
	sort(rem.begin(), rem.end());
	auto it = add.begin();
	auto it2 = rem.begin();
	LL res = 0;
	for (int i = 1; i <= dim; i++) {
		while (it != add.end() && it->first == i) {
			update(it->second.first, it->second.second, 1, dim, 1, 1);
			it++;
		}
		while (it2 != rem.end() && it2->first == i) {
			update(it2->second.first, it2->second.second, 1, dim, -1, 1);
			it2++;
		}
		if (t[1].min == 0) {
			res += t[1].mincnt;
		}
	}
	cout << dim * dim - res << "\n";
	return 0;
}
