#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void hanoi(int A, int B, int C, int n) {
	while (n--) {
		hanoi(A, C, B, n);
		cout << A << " " << C << "\n";
		swap(A, B);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	cout << (1 << n) - 1 << "\n";
	hanoi(1, 2, 3, n);

	return 0;
}
