#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	LL res = 0;
	priority_queue<LL> q;
	while (n--) {
		LL x;
		cin >> x;
		q.push(x);
		res += q.top() - x;
		q.pop();
		q.push(x);
	}
	cout << res << "\n";
	return 0;
}
