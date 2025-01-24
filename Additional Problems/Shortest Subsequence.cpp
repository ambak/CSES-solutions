#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
	ios_base::sync_with_stdio(false);
	string s, res;
	cin >> s;
	vector<int> v[4];
	vector<char> lit = {'A', 'C', 'G', 'T'};
	for (unsigned j = 0; j < s.size(); j++) {
		char x = s[j];
		for (int i = 0; i < 4; i++) {
			if (x == lit[i]) {
				v[i].push_back(j);
			}
		}
	}
	vector<int> ite = {0, 0, 0, 0};
	while (true) {
		bool end = false;
		for (int i = 0; i < 4; i++) {
			if ((int)v[i].size() == ite[i]) {
				res.push_back(lit[i]);
				end = true;
				break;
			}
		}
		if (end) break;
		pair<int, int> p = {0, 0};
		for (int i = 0; i < 4; i++) {
			p = max(p, make_pair(v[i][ite[i]], i));
		}
		res.push_back(lit[p.second]);
		for (int i = 0; i < 4; i++) {
			while (ite[i] < (int)v[i].size() && v[i][ite[i]] <= p.first) {
				ite[i]++;
			}
		}
	}
	cout << res << "\n";
	return 0;
}
