#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
	ios_base::sync_with_stdio(false);
	int lr = 1;
	int res = 1;
	string s;
	cin >> s;
	char last_c = '#';
	for (auto c : s) {
		if (last_c == c) {
			lr++;
		} else {
			last_c = c;
			res = max(res, lr);
			lr = 1;
		}
	}
	cout << max(res, lr) << "\n";
	return 0;
}
