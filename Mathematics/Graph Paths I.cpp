#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL MOD = 1e9L + 7;

class Matrix {
public:
	vector<vector<LL>> t;
	Matrix(int n) {
		t.assign(n, vector<LL>(n));
	}
};

Matrix mul(Matrix &A, Matrix &B, int n) {
	Matrix C(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			C.t[i][j] = 0;
			for (int k = 0; k < n; k++) {
				C.t[i][j] = (C.t[i][j] + A.t[i][k] * B.t[k][j]) % MOD;
			}
		}
	}
	return C;
}

Matrix pow(Matrix A, LL p, int n) {
	Matrix res(n);

	for (int i = 0; i < n; i++) {
		res.t[i][i] = 1;
	}
	while (p) {
		if (p & 1) {
			res = mul(res, A, n);
		}
		A = mul(A, A, n);
		p >>= 1;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	Matrix A(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		A.t[a - 1][b - 1]++;
	}
	cout << pow(A, k, n).t[0][n - 1] << "\n";
	return 0;
}
