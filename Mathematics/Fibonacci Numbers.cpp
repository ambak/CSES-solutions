#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL MOD = 1e9L + 7;

struct Matrix {
	LL t[2][2];
};

Matrix mul(Matrix &A, Matrix &B) {
	Matrix C;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			C.t[i][j] = 0;
			for (int k = 0; k < 2; k++) {
				C.t[i][j] = (C.t[i][j] + A.t[i][k] * B.t[k][j]) % MOD;
			}
		}
	}
	return C;
}

Matrix pow(Matrix A, LL p) {
	Matrix res;
	res.t[0][0] = 1;
	res.t[0][1] = 0;
	res.t[1][0] = 0;
	res.t[1][1] = 1;
	while (p) {
		if (p & 1) {
			res = mul(res, A);
		}
		A = mul(A, A);
		p >>= 1;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	LL n;
	cin >> n;
	Matrix A;
	A.t[0][0] = 0;
	A.t[0][1] = 1;
	A.t[1][0] = 1;
	A.t[1][1] = 1;
	Matrix r = pow(A, n + 1);
	cout << r.t[0][0] << "\n";
	return 0;
}
