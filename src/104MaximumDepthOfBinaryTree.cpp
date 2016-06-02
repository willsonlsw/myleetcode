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
	int maxDepth(TreeNode* root){
		if (root == NULL) return 0;
		return 1 + max(maxDepth(root->left), maxDepth(root->right));
	}
};

int main(){
	return 0;
}