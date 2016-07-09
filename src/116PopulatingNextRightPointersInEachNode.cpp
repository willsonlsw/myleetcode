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
		if (!root) return NULL;
		TreeLinkNode *pre = root, *current;
		while (pre->left) {
			current = pre;
			while (current) {
				current->left->next = current->right;
				if (current->next) current->right->next = current->next->left;
				current = current->next;
			}
			pre = pre->left;
		}
	}
};

int main(){
	return 0;
}