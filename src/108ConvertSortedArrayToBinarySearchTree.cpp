#include <iostream>
#include <vector>

struct TreeNode{
	int val;
	TreeNode *left, *right;
	TreeNode (int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
	TreeNode* buildSubTree(vector<int> &nums, int s, int e){
		if (s >= e) return NULL;
		int mid = (s + e) >> 1;
		TreeNode *node = new TreeNode(nums[mid]);
		if (s == e - 1) return node;
		node->left = buildSubTree(nums, s, mid);
		node->right = buildSubTree(nums, mid + 1, e);
		return node;
	}
	
	TreeNode* sortedArrayToBST(vector<int> &nums){
		if (nums.size() == 0) return NULL;
		return buildSubTree(nums, 0, nums.size());
	}
};

int main(){
	return 0;
}