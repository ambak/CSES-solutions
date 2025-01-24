#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL INF = 1e18L + 5;

class Matrix {
public:
	vector<vector<LL>> t;
	Matrix(int n) {
		t.assign(n, vector<LL>(n));
	}
};

Matrix minmul(Matrix &A, Matrix &B, int n) {
	Matrix C(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			C.t[i][j] = INF;
			for (int k = 0; k < n; k++) {
				C.t[i][j] = min(C.t[i][j], A.t[i][k] + B.t[k][j]);
			}
		}
	}
	return C;
}

Matrix minpow(Matrix A, LL p, int n) {
	Matrix res(n);
	bool st = true;
	while (p) {
		if (p & 1) {
			if (st) {
				st = false;
				res = A;
			} else {
				res = minmul(A, res, n);
			}
		}
		A = minmul(A, A, n);
		p >>= 1;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	Matrix A(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			A.t[i][j] = INF;
		}
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		LL c;
		cin >> a >> b >> c;
		A.t[a - 1][b - 1] = min(A.t[a - 1][b - 1], c);
	}
	LL res = minpow(A, k, n).t[0][n - 1];
	cout << (res >= INF ? -1 : res) << "\n";
	return 0;
}
