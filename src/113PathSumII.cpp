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
	vector<vector<int> > pathSum(TreeNode *root, int sum){
		vector<vector<int> > res;
		vector<int> select;
		if (!root) return res;
		findPathSum(root, select, res, sum);
		return res;
	}
	
	void findPathSum(TreeNode *root, vector<int> &select, vector<vector<int> > &res, int sum){
		if (sum == root->val && root->left == NULL && root->right == NULL) {
			select.push_back(root->val);
			res.push_back(select);
			select.pop_back();
			return;
		}
		sum -= root->val;
		select.push_back(root->val);
		if (root->left != NULL) findPathSum(root->left, select, res, sum);
		if (root->right != NULL) findPathSum(root->right, select, res, sum);
		select.pop_back();
	}
};

int main(){
	return 0;
}