#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

string Manacher(string s) {
	string t;
	for (auto c : s) {
		t.push_back('#');
		t.push_back(c);
	}
	t.push_back('#');
	int n = t.size();
	vector<int> P(n);
	int C = 0, R = 0;
	for (int i = 1; i < n - 1; i++) {
		if (R > i) {
			P[i] = min(R - i, P[2 * C - i]);
		} else {
			P[i] = 0;
		}
		while (i + 1 + P[i] < n && i - 1 - P[i] >= 0 && t[i + 1 + P[i]] == t[i - 1 - P[i]]) {
			P[i]++;
		}
		if (i + P[i] > R) {
			C = i;
			R = P[i] + i;
		}
	}
	int max_len = 0;
	int idx = 0;
	for (int i = 0; i < n; i++) {
		if (P[i] > max_len) {
			max_len = P[i];
			idx = i;
		}
	}
	return s.substr((idx - max_len) / 2, max_len);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	cout << Manacher(s) << "\n";
	return 0;
}
