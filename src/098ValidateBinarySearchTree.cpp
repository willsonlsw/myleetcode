#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left, *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
	bool isSubtreeValidBST(TreeNode *root, long long minval, long long maxval){
		if (!root) return true;
		if (!(minval < root->val && root->val < maxval)) return false;
		return isSubtreeValidBST(root->left, minval, root->val) && isSubtreeValidBST(root->right, root->val, maxval);
	}
	
	bool isValidBST(TreeNode *root){
		if (!root) return true;
		long long maxnum = 0x7ffffffff, minnum = -1 - 0x7ffffffff;
		return isSubtreeValidBST(root->left, minnum, root->val) && isSubtreeValidBST(root->right, root->val, maxnum);
	}
};

int main(){
	return 0;
}