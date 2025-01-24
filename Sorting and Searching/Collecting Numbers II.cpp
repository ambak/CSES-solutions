#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

set<int> v;
int t[200009];
int d[200009];

int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	v.insert(0);
	int res = 1;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		t[i] = a;
		d[a] = i;
		if (v.find(a - 1) == v.end()) {
			res++;
		}
		v.insert(a);
	}
	t[n + 1] = n + 1;
	d[n + 1] = n + 1;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if (a > b) swap(a, b);
		int A = t[a];
		int B = t[b];

		if (d[B - 1] < d[B]) res++;
		if (d[B + 1] > d[B]) res++;
		if (d[A - 1] < d[A]) res++;
		if (d[A + 1] > d[A]) res++;

		swap(t[a], t[b]);
		d[A] = b;
		d[B] = a;

		if (d[B - 1] < d[B]) res--;
		if (d[B + 1] > d[B]) res--;
		if (d[A - 1] < d[A]) res--;
		if (d[A + 1] > d[A]) res--;

		if (A == B + 1) res++;
		if (B == A + 1) res--;

		cout << res << "\n";
	}
	return 0;
}
