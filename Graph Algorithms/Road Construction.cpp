#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct DS {
	int parent;
	int rank;
} d[100009];

void make_set(int x) {
	d[x].parent = x;
	d[x].rank = 1;
}

int find(int x) {
	if (d[x].parent == x) {
		return x;
	}
	d[x].parent = find(d[x].parent);
	return d[x].parent;
}

int union_(int x, int y) {
	int root_x = find(x);
	int root_y = find(y);
	if (root_x == root_y) {
		return -1;
	}
	if (d[root_x].rank > d[root_y].rank) {
		d[root_y].parent = root_x;
		d[root_x].rank += d[root_y].rank;
		return d[root_x].rank;
	}
	d[root_x].parent = root_y;
	d[root_y].rank += d[root_x].rank;
	return d[root_y].rank;
}

int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		make_set(i);
	}
	int maxi = 1;
	int count = n;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		int res = union_(a, b);
		if (res != -1) {
			count--;
			maxi = max(maxi, res);
		}
		cout << count << " " << maxi << "\n";
	}
	return 0;
}
