#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL M = 1 << 18;

struct Q {
	LL v;
	Q *l, *r;
} t[M * 2 + 3];

void setup(LL val, LL b, LL B, LL E, LL id) {
	if (B == E) {
		t[id].v = val;
	} else {
		LL MID = (B + E) / 2;
		if (b <= MID) {
			setup(val, b, B, MID, id * 2);
		}
		if (b > MID) {
			setup(val, b, MID + 1, E, id * 2 + 1);
		}
		t[id].v = t[id * 2].v + t[id * 2 + 1].v;
		t[id].l = &t[id * 2];
		t[id].r = &t[id * 2 + 1];
	}
}

Q *setall(LL val, LL b, LL B, LL E, Q *q) {
	Q *qq = new Q;
	qq->l = q->l;
	qq->r = q->r;
	qq->v = q->v;
	if (B == E) {
		qq->v = val;
		return qq;
	} else {
		LL MID = (B + E) / 2;
		if (b <= MID) {
			qq->l = setall(val, b, B, MID, qq->l);
		}
		if (b > MID) {
			qq->r = setall(val, b, MID + 1, E, qq->r);
		}
		qq->v = qq->l->v + qq->r->v;
	}
	return qq;
}

LL query(LL b, LL e, LL B, LL E, Q *q) {
	if (b <= B && e >= E) {
		return q->v;
	} else {
		LL res = 0;
		LL MID = (B + E) / 2;
		if (b <= MID) {
			res += query(b, e, B, MID, q->l);
		}
		if (e > MID) {
			res += query(b, e, MID + 1, E, q->r);
		}
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
		setup(x, i, 1, M, 1);
	}
	vector<Q *> vec;
	vec.push_back(&t[1]);
	vec.push_back(&t[1]);
	while (q--) {
		LL type, a, b, k, val;
		cin >> type;
		if (type == 1) {
			cin >> k >> a >> val;
			vec[k] = setall(val, a, 1, M, vec[k]);
		} else if (type == 2) {
			cin >> k >> a >> b;
			cout << query(a, b, 1, M, vec[k]) << "\n";
		} else {
			cin >> k;
			vec.push_back(vec[k]);
		}
	}
	return 0;
}
