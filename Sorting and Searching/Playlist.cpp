#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

map<int, int> m;
int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int res = 0;
	int local_res = 0;
	int index = 0;
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		auto it = m.find(k);
		if (it == m.end()) {
			local_res++;
		} else {
			res = max(res, local_res);
			index = max(index, it->second);
			local_res = i - index;
		}
		m[k] = i;
	}
	res = max(res, local_res);
	cout << res << "\n";
	return 0;
}
