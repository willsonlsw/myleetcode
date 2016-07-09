#include <iostream>
#include <vector>

struct TreeNode{
	int val;
	TreeNode *left, *right;
	TreeNode (int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode{
	int val;
	ListNode *next;
	ListNode (int x) : val(x), next(NULL) {}
};

class Solution{
public:
	
	TreeNode* buildSubBST(ListNode* head, int len) {
		if (len < 1) return NULL;
		if (len == 1) return new TreeNode(head->val);
		int mid = len >> 1;
		ListNode *lptr = head, *rptr;
		for (int i = 0; i < mid - 1; ++i)
			lptr = lptr->next;
		rptr = lptr->next;
		TreeNode *node = new TreeNode(rptr->val);
		node->left = buildSubBST(head, mid);
		rptr = rptr->next;
		node->right = buildSubBST(rptr, len - mid - 1);
		return node;
	}
	
	TreeNode* sortedListToBST(ListNode* head) {
		int len = 0;
		ListNode *ptr = head;
		while (ptr) {
			len++;
			ptr = ptr->next;
		}
		if (len == 0) return NULL;
		return buildSubBST(head, len);
	}
};

int main(){
	int n, x;
	ListNode *list;
	
	return 0;
}