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
	vector<vector<int> > levelOrder(TreeNode *root){
		vector<vector<int> > res;
		if (!root) return res;
		vector<TreeNode*> thislevel, nextlevel;
		thislevel.push_back(root);
		int s = 0, e = thislevel.size();
		while (thislevel.size() > 0) {
			vector<int> lev;
			for (int i = 0; i < thislevel.size(); ++i) {
				lev.push_back(thislevel[i]->val);
				if (thislevel[i]->left) nextlevel.push_back(thislevel[i]->left);
				if (thislevel[i]->right) nextlevel.push_back(thislevel[i]->right);
			}
			res.push_back(lev);
			thislevel = nextlevel;
			nextlevel.clear();
		}
		return res;
	}	
};


int main(){
	return 0;
}