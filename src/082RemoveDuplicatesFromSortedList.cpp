#include <iostream>

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {} 
};

class Solution{
public:
	ListNode* deleteDuplicates(ListNode* head){
		if (head == NULL || head->next == NULL) return head;
		ListNode **ptr = &head;
 		while ((*ptr)){
 			if((*ptr)->next && (*ptr)->val == (*ptr)->next->val){
 				ListNode *tmp = *ptr;
 				while (tmp != NULL && tmp->val == (*ptr)->val) tmp = tmp->next;
 				*ptr = tmp;
 			}else ptr = &((*ptr)->next);	
 		}
 		return head;
	}
};

int main(){
	return 0;
}