#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Treap {
public:
	Treap(LL value) : value(value) {
		size = 1;
		weight = rand();
		left = nullptr;
		right = nullptr;
		rev = false;
		sum = value;
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
				A->sum = get_sum(A->left) + get_sum(A->right) + A->value;
				return A;
			} else {
				B->left = merge(A, B->left);
				B->size = get_size(B->left) + get_size(B->right) + 1;
				B->sum = get_sum(B->left) + get_sum(B->right) + B->value;
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
			treap->sum = get_sum(treap->left) + get_sum(treap->right) + treap->value;
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
	static LL get_sum(Treap *treap) {
		return treap ? treap->sum : 0LL;
	}

private:
	int size;
	LL value;
	LL sum;
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
	cin >> n >> m;
	Treap *treap = nullptr;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		treap = treap->merge(treap, new Treap(x));
	}
	while (m--) {
		int type, a, b;
		cin >> type >> a >> b;
		Treap *A = nullptr, *B = nullptr, *C = nullptr, *D = nullptr;
		treap->split(treap, A, B, a - 1);
		treap->split(B, C, D, b - a + 1);
		if (type == 1) {
			C->reverse();

		} else if (type == 2) {
			cout << C->get_sum(C) << "\n";
		}
		treap = treap->merge(A, C);
		treap = treap->merge(treap, D);
	}
	return 0;
}
