#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL M = 1 << 18;

struct Q {
	LL v, b, count;
} t[M * 2 + 3];

void down(LL id, LL B, LL MID) {
	if (t[id].b) {
		t[id * 2].b += t[id].b;
		LL tmp = t[id].b + (MID - B + 1) * t[id].count;
		t[id * 2 + 1].b += tmp;
		t[id * 2].count += t[id].count;
		t[id * 2 + 1].count += t[id].count;
		t[id * 2].v += (t[id].b + t[id].b + (MID - B) * t[id].count) * (MID - B + 1) / 2;
		t[id * 2 + 1].v += (2 * tmp + (MID - B) * t[id].count) * (MID - B + 1) / 2;
		t[id].b = 0;
		t[id].count = 0;
	}
}

void setup(LL val, LL b, LL e, LL B, LL E, LL id) {
	if (b <= B && e >= E) {
		t[id].v = val;
	} else {
		LL MID = (B + E) / 2;
		if (b <= MID) {
			setup(val, b, e, B, MID, id * 2);
		}
		if (e > MID) {
			setup(val, b, e, MID + 1, E, id * 2 + 1);
		}
		t[id].v = t[id * 2].v + t[id * 2 + 1].v;
	}
}

void increase(LL b, LL e, LL B, LL E, LL id) {
	if (b <= B && e >= E) {
		LL st = B - b + 1;
		t[id].b += B - b + 1;
		t[id].count++;
		t[id].v += (st + st + (E - B)) * (E - B + 1) / 2;
	} else {
		LL MID = (B + E) / 2;

		down(id, B, MID);

		if (b <= MID) {
			increase(b, e, B, MID, id * 2);
		}
		if (e > MID) {
			increase(b, e, MID + 1, E, id * 2 + 1);
		}
		t[id].v = t[id * 2].v + t[id * 2 + 1].v;
	}
}

LL query(LL b, LL e, LL B, LL E, LL id) {
	if (b <= B && e >= E) {
		return t[id].v;
	} else {
		LL res = 0;
		LL MID = (B + E) / 2;
		down(id, B, MID);
		if (b <= MID) {
			res += query(b, e, B, MID, id * 2);
		}
		if (e > MID) {
			res += query(b, e, MID + 1, E, id * 2 + 1);
		}
		t[id].v = t[id * 2].v + t[id * 2 + 1].v;
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
		setup(x, i, i, 1, M, 1);
	}
	while (q--) {
		LL x, a, b;
		cin >> x >> a >> b;
		if (x == 1) {
			increase(a, b, 1, M, 1);
		} else {
			cout << query(a, b, 1, M, 1) << "\n";
		}
	}
	return 0;
}
