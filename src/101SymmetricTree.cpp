#include <iostream>
using namespace std;

struct TreeNode{
	int val; 
	TreeNode *left, *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
	bool isSymmetric(TreeNode* root){
		return isSame(root, root);
	}
	
	bool isSame(TreeNode* lroot, TreeNode* rroot){
		if (lroot == NULL && rroot == NULL) return true;
		if (lroot == NULL || rroot == NULL) return false;
		if (lroot->val != rroot->val) return false;
		
		return isSame(lroot->left, rroot->right) && isSame(lroot->right, rroot->left);
	}
};

int main(){
	return 0;
}