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
	string s;
	cin >> s;
	const int n = s.size();
	vector<LL> a(n + 1), b(n + 1), t(n + 1);
	for (int i = 1; i <= n; i++) {
		t[i] = t[i - 1] + s[i - 1] - '0';
	}
	for (int i = 0; i <= n; i++) {
		a[t[i]]++;
	}
	for (int i = 0; i <= n; i++) {
		b[t[n] - t[i]]++;
	}
	auto res = multiply(a, b);
	LL zero = 0;
	vector<LL> z;
	for (auto c : s) {
		if (c == '0')
			zero++;
		else {
			z.push_back(zero);
			zero = 0;
		}
	}
	if (zero) z.push_back(zero);
	zero = 0;
	for (auto x : z) {
		zero += (x + 1) * x / 2;
	}
	cout << zero << " ";
	for (int i = t[n] + 1; i <= t[n] + n; i++) {
		cout << res[i] << " ";
	}
	cout << "\n";
	return 0;
}
