#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

string s[8];

bool check(string a[8]) {
	int sum = 0, sum2 = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (a[i][j] == 'x')
				sum++;
		}
		if (sum != 1) return false;
		sum = 0;
		for (int j = 0; j < 8; j++) {
			if (a[j][i] == 'x')
				sum++;
		}
		if (sum != 1) return false;
		sum = 0;
		for (int j = 0; j < 8; j++) {
			if (a[(j + i) % 8][j] == 'x' && (j + i) < 8)
				sum++;
			if (a[(j + i) % 8][j] == 'x' && (j + i) >= 8)
				sum2++;
		}
		if (sum > 1 || sum2 > 1) return false;
		sum = 0;
		sum2 = 0;
		for (int j = 0; j < 8; j++) {
			if (a[(8 - j + i) % 8][j] == 'x' && (8 - j + i) < 8)
				sum++;
			if (a[(8 - j + i) % 8][j] == 'x' && (8 - j + i) >= 8)
				sum2++;
		}
		if (sum > 1 || sum2 > 1) return false;
		sum = 0;
		sum2 = 0;
	}
	return true;
}

int tab[8] = {0, 1, 2, 3, 4, 5, 6, 7};
vector<vector<int> > permutation;

void create_permutations(int l, int r) {
	if (l == r) {
		vector<int> v;
		for (int i = 0; i < 8; i++)
			v.push_back(tab[i]);
		permutation.push_back(v);
	} else {
		for (int i = l; i <= r; i++) {
			swap(tab[l], tab[i]);
			create_permutations(l + 1, r);
			swap(tab[l], tab[i]);
		}
	}
}

int solve() {
	create_permutations(0, 7);
	string ss[8];
	int res = 0;
	for (unsigned i = 0; i < permutation.size(); i++) {
		bool ok = true;
		for (int j = 0; j < 8; j++) {
			if (s[j][permutation[i][j]] == '*') {
				ok = false;
				break;
			}
			string tmp = "........";
			tmp[permutation[i][j]] = 'x';
			ss[j] = tmp;
		}
		if (ok)
			if (check(ss))
				res++;
	}

	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	for (int i = 0; i < 8; i++)
		cin >> s[i];
	cout << solve() << "\n";
	return 0;
}
