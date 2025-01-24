#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL M = 1 << 18;

struct Q {
	LL v, w, s;
} t[M * 2 + 3];

void down(LL id, LL B, LL MID, LL E) {
	if (id > M) {
		t[id].s = 0;
		t[id].w = 0;
		return;
	}
	if (t[id].s) {
		t[id * 2].s = t[id].s;
		t[id * 2 + 1].s = t[id].s;
		t[id * 2].w = 0;
		t[id * 2 + 1].w = 0;
		t[id * 2].v = t[id].s * (MID - B + 1);
		t[id * 2 + 1].v = t[id].s * (E - MID);
		t[id].s = 0;
	}
	if (t[id].w) {
		t[id * 2].w += t[id].w;
		t[id * 2 + 1].w += t[id].w;
		t[id * 2].v += t[id].w * (MID - B + 1);
		t[id * 2 + 1].v += t[id].w * (E - MID);
		t[id].w = 0;
	}
}

void up(LL id) {
	t[id].v = t[id * 2].v + t[id * 2 + 1].v;
}

void add(LL val, LL b, LL e, LL B, LL E, LL id) {
	if (b <= B && e >= E) {
		t[id].w += val;
		t[id].v += val * (E - B + 1);
	} else {
		LL MID = (B + E) / 2;
		down(id, B, MID, E);
		if (b <= MID) {
			add(val, b, e, B, MID, id * 2);
		}
		if (e > MID) {
			add(val, b, e, MID + 1, E, id * 2 + 1);
		}
		up(id);
	}
}

void setall(LL val, LL b, LL e, LL B, LL E, LL id) {
	if (b <= B && e >= E) {
		t[id].s = val;
		t[id].w = 0;
		t[id].v = val * (E - B + 1);
	} else {
		LL MID = (B + E) / 2;
		down(id, B, MID, E);
		if (b <= MID) {
			setall(val, b, e, B, MID, id * 2);
		}
		if (e > MID) {
			setall(val, b, e, MID + 1, E, id * 2 + 1);
		}
		up(id);
	}
}

LL query(LL b, LL e, LL B, LL E, LL id) {
	if (b <= B && e >= E) {
		return t[id].v;
	} else {
		LL res = 0;
		LL MID = (B + E) / 2;
		down(id, B, MID, E);
		if (b <= MID) {
			res += query(b, e, B, MID, id * 2);
		}
		if (e > MID) {
			res += query(b, e, MID + 1, E, id * 2 + 1);
		}
		up(id);
		return res;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	LL n, q;
	cin >> n >> q;
	for (LL i = 1; i <= n; i++) {
		LL x;
		cin >> x;
		setall(x, i, i, 1, M, 1);
	}
	while (q--) {
		LL x, a, b, val;
		cin >> x >> a >> b;
		if (x == 1) {
			cin >> val;
			add(val, a, b, 1, M, 1);
		} else if (x == 2) {
			cin >> val;
			setall(val, a, b, 1, M, 1);
		} else {
			cout << query(a, b, 1, M, 1) << "\n";
		}
	}
	return 0;
}
