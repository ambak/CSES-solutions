#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct segtree {
	set<LL> s;
	segtree *left;
	segtree *right;
	segtree() {
		left = nullptr;
		right = nullptr;
	}
};

const LL SHIFT = 999999999999999LL;
const LL MINI = 0LL;
const LL MAXI = SHIFT * 2;

void update(LL b, LL e, LL B, LL E, LL val, segtree *S) {
	if (b <= B && e >= E) {
		S->s.insert(val);
	} else {
		LL MID = B / 2 + E / 2 + (B % 2 + E % 2) / 2;
		if (b <= MID) {
			if (S->left == nullptr) {
				segtree *SS = new segtree();
				S->left = SS;
			}
			update(b, e, B, MID, val, S->left);
		}
		if (e > MID) {
			if (S->right == nullptr) {
				segtree *SS = new segtree();
				S->right = SS;
			}
			update(b, e, MID + 1, E, val, S->right);
		}
	}
}

LL retval;

void query(LL b, LL B, LL E, segtree *S, LL pos, LL val, bool lower) {
	if (lower) {
		LL res = -SHIFT;
		auto r = S->s.lower_bound(pos);
		if (r != S->s.begin()) {
			r--;
			if (r != S->s.end() && *r >= val) {
				res = max(res, *r);
				retval = max(retval, res);
			}
		}
	} else {
		LL res = SHIFT;
		auto r = S->s.upper_bound(pos);
		if (r != S->s.end()) {
			if (r != S->s.end() && *r <= val) {
				res = min(res, *r);
				retval = min(retval, res);
			}
		}
	}
	LL MID = B / 2 + E / 2 + (B % 2 + E % 2) / 2;
	if (b <= MID && S->left != nullptr) {
		query(b, B, MID, S->left, pos, val, lower);
	}
	if (b > MID && S->right != nullptr) {
		query(b, MID + 1, E, S->right, pos, val, lower);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	LL res = 0;
	segtree *hor = new segtree();
	segtree *ver = new segtree();
	LL X = 0, Y = 0;
	char prevc = '.';
	while (n--) {
		char c;
		LL dist;
		cin >> c >> dist;
		if (c == 'L') {
			if (prevc == 'R') break;
			retval = -SHIFT;
			query(Y + SHIFT, MINI, MAXI, ver, X, X - dist, true);
			if (retval != -SHIFT) {
				res += (abs(X - retval));
				break;
			}
			update(X - dist + SHIFT, X + SHIFT, MINI, MAXI, Y, hor);
			update(Y + SHIFT, Y + SHIFT, MINI, MAXI, X, ver);
			update(Y + SHIFT, Y + SHIFT, MINI, MAXI, X - dist, ver);
			X -= dist;
		} else if (c == 'R') {
			if (prevc == 'L') break;
			retval = SHIFT;
			query(Y + SHIFT, MINI, MAXI, ver, X, X + dist, false);
			if (retval != SHIFT) {
				res += (abs(X - retval));
				break;
			}
			update(X + SHIFT, X + dist + SHIFT, MINI, MAXI, Y, hor);
			update(Y + SHIFT, Y + SHIFT, MINI, MAXI, X, ver);
			update(Y + SHIFT, Y + SHIFT, MINI, MAXI, X + dist, ver);
			X += dist;
		} else if (c == 'D') {
			if (prevc == 'U') break;
			retval = -SHIFT;
			query(X + SHIFT, MINI, MAXI, hor, Y, Y - dist, true);
			if (retval != -SHIFT) {
				res += (abs(Y - retval));
				break;
			}
			update(Y - dist + SHIFT, Y + SHIFT, MINI, MAXI, X, ver);
			update(X + SHIFT, X + SHIFT, MINI, MAXI, Y, hor);
			update(X + SHIFT, X + SHIFT, MINI, MAXI, Y - dist, hor);
			Y -= dist;
		} else if (c == 'U') {
			if (prevc == 'D') break;
			retval = SHIFT;
			query(X + SHIFT, MINI, MAXI, hor, Y, Y + dist, false);
			if (retval != SHIFT) {
				res += (abs(Y - retval));
				break;
			}
			update(Y + SHIFT, Y + dist + SHIFT, MINI, MAXI, X, ver);
			update(X + SHIFT, X + SHIFT, MINI, MAXI, Y, hor);
			update(X + SHIFT, X + SHIFT, MINI, MAXI, Y + dist, hor);
			Y += dist;
		}
		res += dist;
		prevc = c;
	}

	cout << res << "\n";
	return 0;
}
