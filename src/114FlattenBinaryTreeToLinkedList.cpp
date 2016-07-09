#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left, *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}

class Solution{
public:
	TreeNode* subtreeFlatten(TreeNode *root, TreeNode *tail){
		if (!root) return NULL;
		TreeNode *rhead=NULL, *rtail=root, *lhead=NULL, *ltail=root;
		rhead = subtreeFlatten(root->right, rtail);
		lhead = subtreeFlatten(root->left, ltail);
		if (lhead) {
			root->left = NULL;
			root->right = lhead;
			ltail->right = rhead;
			tail = rtail;
		}else{
			root->right = rhead;
			tail = rtail;
		}
		return root;
	}
	
	void flatten(TreeNode *root){
		if (!root) return;
		TreeNode *tail;
		subtreeFlatten(root, tail);
	}
};


int main(){
	return 0;
}