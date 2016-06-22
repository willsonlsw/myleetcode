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
	
	/*
	TreeNode* findTheWrongNode(TreeNode *root, TreeNode *misn, long long maxval, long long minval) {
		if (root == NULL) return NULL;
		if (!(minval < root->val && root->val < maxval) && root != misn) return root;
		TreeNode *res = findTheWrongNode(root->left, misn, root->val, minval);
		if (res != NULL) return res;
		return findTheWrongNode(root->right, misn, maxval, root->val);
	}
	
	void recoverTree(TreeNode *root){
		long long maxval = 0xffffffff, minval = 0 - 0xffffffff;
		TreeNode *wn1=NULL, *wn2=NULL;
		wn1 = findTheWrongNode(root, wn1, maxval, minval);
		wn2 = findTheWrongNode(root, wn1, maxval, minval);
		int tmp = wn1->val;
		wn1->val = wn2->val;
		wn2->val = tmp; 
	}*/
};

int main(){
	return 0;
}
