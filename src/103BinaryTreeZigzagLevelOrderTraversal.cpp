#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left, *right;
	TreeNode (int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
	vector<vector<int> > zigzagLevelOrder(TreeNode *root){
		vector<vector<int> > res;
		if (!root) return res;
		vector<TreeNode*> thislevel, nextlevel;
		thislevel.push_back(root);
		int count = 0;
		while (thislevel.size() > 0) {
			vector<int> lev;
			for (int i = 0; i < thislevel.size(); ++i) {
				lev.push_back(thislevel[i]->val);
				if (thislevel[i]->left) nextlevel.push_back(thislevel[i]->left);
				if (thislevel[i]->right) nextlevel.push_back(thislevel[i]->right);
			}
			if (count % 2 == 1) reverse(lev.begin(), lev.end());
			res.push_back(lev);
			thislevel = nextlevel;
			nextlevel.clear();
			count++;
		}
		return res;
	}	
};

int main(){
	return 0;
}