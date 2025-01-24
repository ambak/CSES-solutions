#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	v.push_back(0);
	v.push_back(1);

	for (int i = 1; i < n; i++) {
		int length = v.size();
		for (int j = length - 1; j >= 0; j--) {
			v.push_back((1 << i) ^ v[j]);
		}
	}

	for (int a : v) {
		bitset<16> x(a);
		string res = x.to_string();
		for (int i = 16 - n; i < 16; i++) {
			cout << res[i];
		}
		cout << "\n";
	}

	return 0;
}
