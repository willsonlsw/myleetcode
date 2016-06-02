#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left, *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
		if (preorder.size() == 0 || inorder.size() == 0) return NULL;
		if (preorder.size() != inorder.size()) return NULL;
		return buildSubTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
	}
	
	TreeNode* buildSubTree(vector<int>& preorder, int prel, vector<int>& inorder, int inl, int inr){
		if (inl > inr) return NULL; 
		int rval = preorder[prel];
		TreeNode *root = new TreeNode(rval);
		int idx;
		for (int i = inl; i <= inr; ++i)
			if (inorder[i] == rval) {
				idx = i;
				break;
			}
		root->left = buildSubTree(preorder, prel+1, inorder, inl, idx-1);
		int prelr = prel + (idx - inl);
		root->right = buildSubTree(preorder, prelr+1, inorder, idx+1, inr);
		return root;
	}
};

int main(){
	return 0;
}