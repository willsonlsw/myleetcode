#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
	bool hasPathSum(TreeNode *root, int sum){
		if (root == NULL) return false;
		if (root->val == sum && root->left == NULL && root->right == NULL) return true;
		if (root->left != NULL) {
			if (hasPathSum(root->left, sum - root->val)) return true;
		}
		if (root->right != NULL) {
			return hasPathSum(root->right, sum - root->val);
		}
		return false;
	}
};

int main(){
	return 0;
}