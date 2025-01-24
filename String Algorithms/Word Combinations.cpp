#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL MOD = 1e9 + 7;

class Trie {
public:
	Trie() {
		for (int i = 0; i < 26; i++) v[i] = NULL;
		end = false;
	}
	~Trie() {
		for (int i = 0; i < 26; i++) {
			if (v[i] != NULL) delete v[i];
		}
	}

	void insert(string &w) {
		Trie *t = this;
		for (auto c : w) {
			if (t->v[c - 'a'] == NULL) {
				t->v[c - 'a'] = new Trie;
			}
			t = t->v[c - 'a'];
		}
		t->end = true;
	}

	Trie *v[26];
	bool end;
} trie;

int main() {
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		string ss;
		cin >> ss;
		trie.insert(ss);
	}
	vector<LL> dp(s.size() + 1);
	dp[0] = 1;
	for (unsigned i = 1; i < dp.size(); i++) {
		Trie *t = &trie;
		unsigned j = i - 1;
		while (t != NULL) {
			if (t->end) {
				dp[j] = (dp[j] + dp[i - 1]) % MOD;
			}
			if (j == s.size()) break;
			t = t->v[s[j] - 'a'];
			j++;
		}
	}
	cout << dp[s.size()] << "\n";
	return 0;
}
