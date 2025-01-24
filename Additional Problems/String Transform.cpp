#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

string BurrowsWheelerTransformDecode(string s) {
	int n = s.size();
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		v[i] = i;
	}
	stable_sort(v.begin(), v.end(), [&s](int a, int b) { return s[a] < s[b]; });
	int x = v[0];
	string res;
	while (x != 0) {
		x = v[x];
		res.push_back(s[x]);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	cout << BurrowsWheelerTransformDecode(s) << "\n";
	return 0;
}
