#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class AhoCorasick {
public:
	AhoCorasick() {
		for (int i = 0; i < 26; i++) v[i] = nullptr;
		end = false;
		vis = false;
		fail = nullptr;
		parent = nullptr;
	}

	void insert(string &w, int id, vector<AhoCorasick *> &ending) {
		AhoCorasick *t = this;
		for (auto c : w) {
			if (t->v[c - 'a'] == nullptr) {
				t->v[c - 'a'] = new AhoCorasick;
				t->v[c - 'a']->parent = t;
				t->v[c - 'a']->c = c;
			}
			t = t->v[c - 'a'];
		}
		t->end = true;
		ending[id] = t;
	}

	void build() {
		queue<AhoCorasick *> q;
		this->fail = this;
		for (int i = 0; i < 26; i++) {
			if (this->v[i] != nullptr) {
				q.push(this->v[i]);
			}
		}
		while (!q.empty()) {
			auto x = q.front();
			q.pop();
			for (int i = 0; i < 26; i++) {
				if (x->v[i] != nullptr) {
					q.push(x->v[i]);
				}
			}
			if (x->parent == this) {
				x->fail = this;
			} else {
				auto tmp = x->parent->fail;
				auto c = x->c;
				while (tmp != this && tmp->v[c - 'a'] == nullptr) tmp = tmp->fail;
				if (tmp->v[c - 'a']) tmp = tmp->v[c - 'a'];
				x->fail = tmp;
			}
		}
	}

	void search(string &s) {
		auto tmp = this;
		for (auto c : s) {
			while (tmp != this && tmp->v[c - 'a'] == nullptr) tmp = tmp->fail;
			if (tmp->v[c - 'a']) tmp = tmp->v[c - 'a'];
			tmp->vis = true;
		}
	}

	void find_visited() {
		queue<AhoCorasick *> q;
		for (int i = 0; i < 26; i++) {
			if (this->v[i] != nullptr) {
				q.push(this->v[i]);
			}
		}
		while (!q.empty()) {
			auto x = q.front();
			q.pop();
			auto y = x;
			while (y->vis && y->fail != this && !y->fail->vis) {
				y->fail->vis = true;
				y = y->fail;
			}
			for (int i = 0; i < 26; i++) {
				if (x->v[i] != nullptr) {
					q.push(x->v[i]);
				}
			}
		}
	}

	bool is_visited() {
		return vis;
	}

private:
	AhoCorasick *v[26];
	bool end, vis;
	AhoCorasick *fail, *parent;
	char c;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	int n;
	cin >> n;
	AhoCorasick *root = new AhoCorasick;
	vector<AhoCorasick *> ending(n);
	for (int i = 0; i < n; i++) {
		string w;
		cin >> w;
		root->insert(w, i, ending);
	}
	root->build();
	root->search(s);
	root->find_visited();
	for (int i = 0; i < n; i++) {
		if (ending[i]->is_visited()) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}
