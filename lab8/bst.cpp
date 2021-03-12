#include "bst.h"

using namespace std;

int rangeSum(Node *root, int L, int R) {
	int value = 0; 
	if (root == nullptr) {
		return value;
	}
	if (root->key >= L && root->key <= R) {
		value = root->key;
	}
	if (root->left != NULL) {
		value += rangeSum(root->left, L, R);
	}
	if (root->right != NULL) {
		value += rangeSum(root->right, L, R);
	}
	return value;
}
