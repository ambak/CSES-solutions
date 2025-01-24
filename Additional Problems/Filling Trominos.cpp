#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const string ninefive[9] = {"ADDAA", "AADCA", "BBCCB", "BDDBB", "AADAA", "ACCAB", "BBCBB", "BADAA", "AADDA"};
const string fivenine[5] = {"AABBABBAA", "ACCBAABAD", "DDCDDCCDD", "DABDACBAA", "AABBAABBA"};
const string threeetwo1[3] = {"EE", "EF", "FF"};
const string threeetwo2[3] = {"GG", "GH", "HH"};
const string twothree1[2] = {"OOP", "OPP"};
const string twothree2[2] = {"QQR", "QRR"};

char res[100][100];

void print_threetwo(int nn, int mm, int n, int m) {
	for (int i = nn; i < n; i++) {
		for (int j = mm; j < m; j++) {
			if ((((i - nn) / 3) % 2 == 0 && ((j - mm) / 2) % 2 == 0) || (((i - nn) / 3) % 2 == 1 && ((j - mm) / 2) % 2 == 1)) {
				res[i][j] = threeetwo1[(i - nn) % 3][(j - mm) % 2];
			} else {
				res[i][j] = threeetwo2[(i - nn) % 3][(j - mm) % 2];
			}
		}
	}
}

void print_twothree(int nn, int mm, int n, int m) {
	for (int i = nn; i < n; i++) {
		for (int j = mm; j < m; j++) {
			if ((((i - nn) / 2) % 2 == 0 && ((j - mm) / 3) % 2 == 0) || (((i - nn) / 2) % 2 == 1 && ((j - mm) / 3) % 2 == 1)) {
				res[i][j] = twothree1[(i - nn) % 2][(j - mm) % 3];
			} else {
				res[i][j] = twothree2[(i - nn) % 2][(j - mm) % 3];
			}
		}
	}
}

void print_ninefive() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 5; j++) {
			res[i][j] = ninefive[i][j];
		}
	}
}

void print_fivenine() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			res[i][j] = fivenine[i][j];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		if (n == 1 || m == 1) {
			cout << "NO\n";
			continue;
		} else if (n % 3 == 0 && m % 2 == 0) {
			print_threetwo(0, 0, n, m);
		} else if (m % 3 == 0 && n % 2 == 0) {
			print_twothree(0, 0, n, m);
		} else if (n % 6 == 0 && m % 2 == 1) {
			print_twothree(0, 0, n, 3);
			print_threetwo(0, 3, n, m);
		} else if (m % 6 == 0 && n % 2 == 1) {
			print_threetwo(0, 0, 3, m);
			print_twothree(3, 0, n, m);
		} else if (n % 3 == 0 && m % 2 == 1 && n >= 9 && m >= 5) {
			print_ninefive();
			print_threetwo(9, 0, n, 2);
			print_twothree(9, 2, n, 5);
			print_threetwo(0, 5, n, m);
		} else if (m % 3 == 0 && n % 2 == 1 && m >= 9 && n >= 5) {
			print_fivenine();
			print_twothree(0, 9, 2, m);
			print_threetwo(2, 9, 5, m);
			print_twothree(5, 0, n, m);
		} else {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << res[i][j];
			}
			cout << "\n";
		}
	}
	return 0;
}
