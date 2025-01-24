#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Treap {
public:
	Treap(char value) : value(value) {
		size = 1;
		weight = rand();
		left = nullptr;
		right = nullptr;
		rev = false;
	}
	static Treap *merge(Treap *A, Treap *B) {
		push(A);
		push(B);
		if (A == nullptr)
			return B;
		else if (B == nullptr)
			return A;
		else {
			if (A->weight > B->weight) {
				A->right = merge(A->right, B);
				A->size = get_size(A->right) + get_size(A->left) + 1;
				return A;
			} else {
				B->left = merge(A, B->left);
				B->size = get_size(B->left) + get_size(B->right) + 1;
				return B;
			}
		}
	}
	static void split(Treap *treap, Treap *&A, Treap *&B, int k) {
		push(treap);
		if (treap == nullptr) {
			A = nullptr;
			B = nullptr;
		} else {
			if (get_size(treap->left) < k) {
				split(treap->right, treap->right, B, k - get_size(treap->left) - 1);
				A = treap;
			} else {
				split(treap->left, A, treap->left, k);
				B = treap;
			}
			treap->size = get_size(treap->left) + get_size(treap->right) + 1;
		}
	}

	static void print(Treap *treap) {
		push(treap);
		if (treap == nullptr) return;
		print(treap->left);
		cout << treap->value;
		print(treap->right);
	}

	void reverse() {
		this->rev = true;
	}

private:
	int size;
	char value;
	int weight;
	bool rev;
	Treap *left;
	Treap *right;
	static int get_size(Treap *treap) {
		return treap ? treap->size : 0;
	}
	static void push(Treap *treap) {
		if (treap != nullptr && treap->rev) {
			treap->rev = false;
			swap(treap->left, treap->right);
			if (treap->left != nullptr) {
				treap->left->rev ^= true;
			}
			if (treap->right != nullptr) {
				treap->right->rev ^= true;
			}
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	srand(42);
	int n, m;
	string s;
	cin >> n >> m >> s;
	Treap *treap = nullptr;
	for (auto c : s) {
		treap = treap->merge(treap, new Treap(c));
	}
	while (m--) {
		int a, b;
		cin >> a >> b;
		Treap *A = nullptr, *B = nullptr, *C = nullptr, *D = nullptr;
		treap->split(treap, A, B, a - 1);
		treap->split(B, C, D, b - a + 1);
		C->reverse();
		treap = treap->merge(A, C);
		treap = treap->merge(treap, D);
	}
	treap->print(treap);
	return 0;
}
