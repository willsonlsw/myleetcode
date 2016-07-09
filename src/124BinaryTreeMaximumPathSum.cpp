#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left, *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
	unordered_map<TreeNode*, int> len; 
	
	int getMaxLen(TreeNode *root){
		if (!root) return 0;
		auto itr = len.find(root);
		if (itr != len.end()) return itr->second;
		
		int ll = 0, rl = 0;
		if (root->left) ll = getMaxLen(root->left);
		if (root->right) rl = getMaxLen(root->right);
		
		int tmp = ll > rl ? ll : rl;
		if (tmp > 0) len[root] = root->val + tmp;  
		else len[root] = root->val;
		return len[root];
	} 
	
	void findMaxLen(TreeNode *root, int &maxlen){
		maxlen = max(maxlen, getMaxLen(root));
		maxlen = max(maxlen, getMaxLen(root->left) + getMaxLen(root->right) + root->val);
		if (root->left) findMaxLen(root->left, maxlen);
		if (root->right) findMaxLen(root->right, maxlen);
	}
	
	int maxPathSum(TreeNode *root) {
		if (!root) return 0;
		int maxlen = -1 - 0x7fffffff;
		findMaxLen(root, maxlen);
		return maxlen;
	}
};

int main(){
	return 0;
}