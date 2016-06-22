#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left, *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL {}
};

class Solution{
public:
	int getHeight(TreeNode *root, unordered_map<TreeNode*, int> &treeheight){
		if (!root) return 0;
		unordered_map<TreeNode*, int>::iterator itr = treeheight.find(root);
		if (itr != treeheight.end()) return itr->second;
		
		treeheight[root] = 1 + max(getHeigth(root->left, treeheight), getHeight(root->rigth, treeheight));
		return treeheight[root];
	}
	
	bool isSubtreeBalanced(TreeNode *root, unordered_map<TreeNode*, int> &treeheight) {
		if (!root) return true;
		int lh = getHeight(root->left, treeheight), rh = getHeight(root->right, treeheight);
		if ((lh > rh + 1) || (rh > lh + 1)) return false;
		return isSubtreeBalanced(root->left, treeheight) && isSubtreeBalanced(root->right, treeheight);
	}
	
	bool isBalanced(TreeNode *root){
		unordered_map<TreeNode*, int> treeheight;
		treeheight[root] = getHeight(root, treeheigth);
	}
};

int mai(){
	return 0;
}