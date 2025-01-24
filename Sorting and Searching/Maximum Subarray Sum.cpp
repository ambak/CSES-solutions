#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	LL maxi = 0;
	LL curr = 0;
	int positive = 0;
	LL maxnegative = -999999999999L;
	for (int i = 0; i < n; i++) {
		LL x;
		cin >> x;
		curr += x;
		if (curr < 0)
			curr = 0;
		maxi = max(curr, maxi);
		if (x >= 0) positive++;
		if (x < 0) maxnegative = max(maxnegative, x);
	}
	if (positive)
		cout << maxi << "\n";
	else
		cout << maxnegative << "\n";
	return 0;
}
