#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL MOD = 1e9L + 7;

class Matrix {
public:
	LL t[6][6];
	Matrix() {
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				t[i][j] = 0;
			}
		}
	}
};

Matrix mul(Matrix &A, Matrix &B) {
	Matrix C;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			C.t[i][j] = 0;
			for (int k = 0; k < 6; k++) {
				C.t[i][j] = (C.t[i][j] + A.t[i][k] * B.t[k][j]) % MOD;
			}
		}
	}
	return C;
}

Matrix pow(Matrix A, LL p) {
	Matrix res;

	for (int i = 0; i < 6; i++) {
		res.t[i][i] = 1;
	}
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
	pair<int, int> tmp[11] = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 0}, {5, 1}, {5, 2}, {5, 3}, {5, 4}, {5, 5}};
	for (int i = 0; i < 11; i++) {
		A.t[tmp[i].first][tmp[i].second] = 1;
	}
	LL vec[6] = {1, 1, 2, 4, 8, 16};
	if (n < 6) {
		cout << vec[n] << "\n";
	} else {
		Matrix r = pow(A, n - 5);
		LL res = 0;
		for (int i = 0; i < 6; i++) {
			res += (vec[i] * r.t[5][i]) % MOD;
		}
		cout << res % MOD << "\n";
	}
	return 0;
}
