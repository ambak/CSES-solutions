#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class BinaryTree {
public:
	BinaryTree(int val) : val(val) {
		parent = nullptr;
		left = nullptr;
		right = nullptr;
	}
	~BinaryTree() {
		if (left != nullptr) {
			delete left;
		}
		if (right != nullptr) {
			delete right;
		}
	}
	friend ostream &operator<<(ostream &os, BinaryTree const *bt) {
		if (bt->left != nullptr) {
			os << bt->left;
		}
		if (bt->right != nullptr) {
			os << bt->right;
		}
		os << bt->val << " ";
		return os;
	}

	BinaryTree *parent;
	BinaryTree *left;
	BinaryTree *right;
	int val;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> preorder(n);
	vector<int> inorder(n);
	vector<int> postorder(n);
	for (auto &x : preorder) cin >> x;
	for (auto &x : inorder) cin >> x;
	vector<bool> odw(n + 1);
	int i = 1, j = 0;
	BinaryTree *root = new BinaryTree(preorder[0]);
	BinaryTree *act = root;
	odw[preorder[0]] = true;
	for (; i < n;) {
		if (odw[inorder[j]] == true) {
			if (odw[inorder[j + 1]] == true) {
				int val = act->val;
				act = act->parent;
				if (act->right != nullptr && act->right->val == val) {
					j--;
				}
			} else {
				act->right = new BinaryTree(preorder[i]);
				act->right->parent = act;
				odw[preorder[i]] = true;
				i++;
				act = act->right;
			}
			j++;
		} else {
			act->left = new BinaryTree(preorder[i]);
			act->left->parent = act;
			odw[preorder[i]] = true;
			i++;
			act = act->left;
		}
	}
	cout << root << "\n";
	delete root;
	return 0;
}
