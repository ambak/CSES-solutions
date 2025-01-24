#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
	ios_base::sync_with_stdio(false);
	const int M = 1e6 + 5;
	vector<int> divisors(M);
	for (int i = 1; i < M; i++) {
		for (int j = i; j < M; j += i) {
			divisors[j]++;
		}
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		cout << divisors[x] << "\n";
	}
	return 0;
}
