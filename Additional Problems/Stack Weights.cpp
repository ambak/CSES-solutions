#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int M = 1 << 19;

struct Q {
	int maxi, mini, w;
} t[M * 2 + 5];

void down(int st, int B, int E) {
	if (B != E) {
		t[st * 2].maxi += t[st].w;
		t[st * 2].mini += t[st].w;
		t[st * 2].w += t[st].w;
		t[st * 2 + 1].maxi += t[st].w;
		t[st * 2 + 1].mini += t[st].w;
		t[st * 2 + 1].w += t[st].w;
	}
	t[st].w = 0;
}

void update(int b, int e, int B, int E, int val, int st) {
	if (b <= B && e >= E) {
		t[st].maxi += val;
		t[st].mini += val;
		t[st].w += val;
		return;
	}
	down(st, B, E);
	const int MID = (B + E) / 2;
	if (b <= MID) update(b, e, B, MID, val, st * 2);
	if (e > MID) update(b, e, MID + 1, E, val, st * 2 + 1);
	t[st].maxi = max(t[st * 2].maxi, t[st * 2 + 1].maxi);
	t[st].mini = min(t[st * 2].mini, t[st * 2 + 1].mini);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	while (n--) {
		int a, b;
		cin >> a >> b;
		if (b == 1) update(1, a, 1, M, 1, 1);
		if (b == 2) update(1, a, 1, M, -1, 1);
		if (t[1].maxi > 0 && t[1].mini >= 0)
			cout << ">\n";
		else if (t[1].maxi <= 0 && t[1].mini < 0)
			cout << "<\n";
		else
			cout << "?\n";
	}
	return 0;
}
