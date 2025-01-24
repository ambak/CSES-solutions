#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int t[200009];
int main() {
	ios_base::sync_with_stdio(false);
	LL n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int tmp;
		cin >> tmp;
		t[tmp] = 1;
	}
	for (int i = 1; i < n + 1; i++) {
		if (!t[i])
			cout << i << "\n";
	}
	return 0;
}
