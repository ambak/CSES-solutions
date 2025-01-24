#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void FFT(vector<complex<double>> &a, bool invert) {
	int n = a.size();
	if (n == 1) return;
	vector<complex<double>> a0(n / 2), a1(n / 2);
	for (int i = 0; i * 2 < n; i++) {
		a0[i] = a[i * 2];
		a1[i] = a[i * 2 + 1];
	}
	FFT(a0, invert);
	FFT(a1, invert);
	double angle = 2 * M_PI / n * (invert ? -1 : 1);
	complex<double> w(1), wn(cos(angle), sin(angle));
	for (int i = 0; i * 2 < n; i++) {
		a[i] = a0[i] + w * a1[i];
		a[i + n / 2] = a0[i] - w * a1[i];
		if (invert) {
			a[i] /= 2;
			a[i + n / 2] /= 2;
		}
		w *= wn;
	}
}

vector<LL> multiply(vector<LL> const &a, vector<LL> const &b) {
	vector<complex<double>> fa(a.begin(), a.end());
	vector<complex<double>> fb(b.begin(), b.end());
	int n = 1;
	while (n < (int)a.size() + (int)b.size()) {
		n *= 2;
	}
	fa.resize(n);
	fb.resize(n);
	FFT(fa, false);
	FFT(fb, false);
	for (int i = 0; i < n; i++) {
		fa[i] *= fb[i];
	}
	FFT(fa, true);
	vector<LL> res(n);
	for (int i = 0; i < n; i++) {
		res[i] = round(fa[i].real());
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int k, n, m;
	cin >> k >> n >> m;
	vector<LL> a(k), b(k);
	for (int i = 0; i < n; i++) {
		LL x;
		cin >> x;
		a[x - 1]++;
	}
	for (int i = 0; i < m; i++) {
		LL x;
		cin >> x;
		b[x - 1]++;
	}
	auto res = multiply(a, b);
	for (int i = 0; i < 2 * k - 1; i++) {
		cout << res[i] << " ";
	}
	return 0;
}
