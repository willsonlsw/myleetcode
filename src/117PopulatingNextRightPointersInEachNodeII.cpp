#include <iostream>
#include <vector>
using namespace std;

struct TreeLinkNode{
	int val;
	TreeLinkNode *left, *next, *right;
	TreeLinkNode(int x) : val(x), left(NULL), next(NULL), right(NULL) {}
};

class Solution{
public:
	void connect(TreeLinkNode *root){
		if (!root) return;
		TreeLinkNode *pre = root, *cur;
		
		while (pre){
			cur = pre;
			TreeLinkNode *tmp = NULL, *leftmost = NULL;
			while (cur) {
				while (cur && !(cur->left || cur->right)) cur = cur->next;
				if (!cur) break;
				if (cur->left && cur->right) cur->left->next = cur->right;
				if (tmp == NULL) {
					if (cur->left) tmp = cur->left;
					else tmp = cur->right;
					leftmost = tmp;
					if (cur->right) tmp = cur->right;
				}else{
					if (cur->left) {
						tmp->next = cur->left;
						tmp = cur->left;
					}
					if (cur->right) {
						tmp->next = cur->right;
						tmp = cur->right;
					}
				}
				cur = cur->next;
			}
			pre = leftmost;
		}
	}
};

TreeLinkNode* buildTree(vector<int> &nums) {
	TreeLinkNode *root = new TreeLinkNode(nums[0]);
	vector<vector<TreeLinkNode*> > lev(2, vector<TreeLinkNode*>());
	lev[0].push_back(root);
	int i = 1, levi = 0, nextlevi; 
	while (lev[levi].size() > 0){
		nextlevi = 1 - levi;
		for (int h = 0; h < lev[levi].size(); ++h) {
			TreeLinkNode *node = lev[levi][h];
			if (i < nums.size() && nums[i] != -1) {
				TreeLinkNode *tmpn = new TreeLinkNode(nums[i]);
				node->left = tmpn;
				lev[nextlevi].push_back(tmpn);
			}
			if (i + 1 < nums.size() && nums[i+1] != -1) {
				TreeLinkNode *tmpn = new TreeLinkNode(nums[i+1]);
				node->right = tmpn;
				lev[nextlevi].push_back(tmpn);
			}
			i += 2;
		}
		lev[levi].clear();
		levi = nextlevi;
	}
	return root;
}

void preorderOutput(TreeLinkNode *root){
	if (!root) return;
	cout << root->val << " ";
	preorderOutput(root->left);
	preorderOutput(root->right);
}

void levelOutput(TreeLinkNode *root){
	TreeLinkNode *nextleftmost = NULL, *pre = root, *cur;
	
	while (pre) {
		cur = pre;
		nextleftmost = NULL;
		while (cur) {
			cout << cur->val << " ";
			if (!nextleftmost && cur->left) nextleftmost = cur->left;
			else if (!nextleftmost && cur->right) nextleftmost = cur->right;
			cur = cur->next;
		}
		cout << endl;
		pre = nextleftmost;
	}
}

int main(){
	int n, x;
	vector<int> nums;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		nums.push_back(x);
	}
	TreeLinkNode *root = buildTree(nums);
	preorderOutput(root);
	cout << endl;
	Solution sc;
	sc.connect(root);
	preorderOutput(root);
	cout << endl;
	levelOutput(root);
	return 0;
}