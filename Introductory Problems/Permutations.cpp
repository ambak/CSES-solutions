#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int tab[4][7] = {{2, 4, 1, 3}, {4, 2, 5, 3, 1}, {6, 2, 4, 1, 5, 3}, {7, 3, 5, 1, 4, 2, 6}};

void f(int start, int id) {
	for (int i = 0; i < id; i++) {
		cout << tab[id - 4][i] + start << " ";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	if (n == 1) {
		cout << "1\n";
	} else if (n == 2 || n == 3) {
		cout << "NO SOLUTION\n";
	} else {
		int start = 0;
		while (start != n) {
			if (n - start > 7) {
				f(start, 4);
				start += 4;
			} else {
				for (int i = 4; i <= 7; i++) {
					if (n - start == i) {
						f(start, i);
						start += i;
					}
				}
			}
		}
	}
	return 0;
}
