#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct dsu {
	int parent, size;
} d[100009];

int find(int a) {
	if (d[a].parent == a) {
		return a;
	}
	d[a].parent = find(d[a].parent);
	return d[a].parent;
}

void unite(int a, int b) {
	int A = find(a);
	int B = find(b);
	if (A == B) return;
	if (d[A].size > d[B].size) {
		d[B].parent = A;
		d[A].size += d[B].size;
	} else {
		d[A].parent = B;
		d[B].size += d[A].size;
	}
}

void makeset(int a) {
	d[a].parent = a;
	d[a].size = 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		makeset(i);
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		unite(a, b);
	}
	bitset<100009> bit;
	bit[0] = 1;
	for (int i = 1; i <= n; i++) {
		if (d[i].parent == i) {
			bit |= bit << d[i].size;
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << bit[i];
	}
	cout << "\n";
	return 0;
}
