#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Trie {
public:
	Trie() {
		for (int i = 0; i < 2; i++) v[i] = NULL;
		end = false;
	}
	~Trie() {
		for (int i = 0; i < 2; i++) {
			if (v[i] != NULL) delete v[i];
		}
	}
	void insert(int x) {
		Trie *t = this;
		for (int i = 30; i >= 0; i--) {
			int pos = x & (1 << i) ? 1 : 0;
			if (t->v[pos] == NULL) {
				t->v[pos] = new Trie;
			}
			t = t->v[pos];
		}
		t->end = true;
	}
	int query(int x) {
		int res = 0;
		Trie *t = this;
		for (int i = 30; i >= 0; i--) {
			int pos = x & (1 << i) ? 1 : 0;
			if (t->v[pos] != NULL) {
				res |= x & (1 << i);
				t = t->v[pos];
			} else {
				res |= (x & (1 << i)) ^ (1 << i);
				t = t->v[pos ^ 1];
			}
		}

		return res;
	}

private:
	Trie *v[2];
	bool end;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto &x : v) cin >> x;
	int XOR = 0;
	int res = 0;
	Trie trie;
	trie.insert(0);
	for (auto x : v) {
		XOR ^= x;
		res = max(res, trie.query(~XOR) ^ XOR);
		trie.insert(XOR);
	}
	cout << res << "\n";
	return 0;
}
