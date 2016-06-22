#include <iostream>
#include <vector>

struct TreeNode{
	int val;
	TreeNode *left, *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}

class Solution{
public:
	TreeNode* buildSubtree(vector<int> &inorder, int is, int ie, vector<int> &postorder, int ps, int pe){
	    //cout << inorder[pe] << endl;
	    TreeNode *node = new TreeNode(postorder[pe]);
		if (is == ie) return node;
		if (is > ie) return NULL;
    
		int x;
		for (x = is; x <= ie; ++x)
			if (inorder[x] == postorder[pe]) break;
		int ll = x - is, rl = ie - x;
		node->left = buildSubtree(inorder, is, x-1, postorder, ps, pe - rl - 1);
		node->right = buildSubtree(inorder, x+1, ie, postorder, pe - rl, pe - 1);
		/*
		cout << node->val << " ";
		if (node->left) cout << node->left->val << " ";
		else cout << "NULL" << " ";
	    if (node->right) cout << node->right->val << " ";
	    else cout << "NULL" << " ";
	    cout << endl;
		*/
		return node;
	}
	
	TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder) {
	    if (inorder.size() == 0) {
	        return NULL;
	    }
		return buildSubtree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
	}
};

int main(){
	return 0;
}