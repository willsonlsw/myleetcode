#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


class Solution{
public:
	ListNode* insertionSortList(ListNode* head){
		if (head == NULL || head->next == NULL) return head;
			
		ListNode *ptr1 = head->next, *ptr2 = head, *ph1, *ph2, *tmp;
		while (ptr != NULL){
			ph1 = ph2 = head;
			while (ph1 != ptr && ph1->val < ptr->val) {
				if (ph1 == head) ph1 = ph1->next;
				else {
					ph2 = ph2->next;
					ph1 = ph1->next;
				}
			}
			if (ph1 == head) {
				head = ptr;
				head->next = ph1;
			}else{
				
			}
		
		}
		
		return head;
	}
};


int main(){
	return 0;
}