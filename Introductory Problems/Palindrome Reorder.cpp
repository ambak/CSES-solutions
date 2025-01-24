#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int t[200];
int main() {
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	for (auto c : s) {
		t[c]++;
	}
	char letter = 0;
	for (char a = 'A'; a <= 'Z'; a++) {
		if (t[a] % 2 == 1) {
			if (letter == 0) {
				letter = a;
			} else {
				letter = 1;
			}
		}
	}
	if (letter == 1 || (letter && s.size() % 2 == 0)) {
		cout << "NO SOLUTION";
	} else {
		for (char a = 'A'; a <= 'Z'; a++) {
			for (int i = 0; i < t[a] / 2; i++) {
				cout << a;
			}
		}
		if (letter)
			cout << letter;
		for (char a = 'Z'; a >= 'A'; a--) {
			for (int i = 0; i < t[a] / 2; i++) {
				cout << a;
			}
		}
	}
	return 0;
}
