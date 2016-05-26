#include <iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}
};

class Solution{
public:
	ListNode* rotateRight(ListNode* head, int k){
		ListNode *tmp = head;
		int n = 0;
		while (tmp != NULL) {
			tmp = tmp->next;
			n++;
		}
		if (n <= 1) return head;
			
		k = k % n;
		int count = 0;
		ListNode *fast=head, *slow=head;
		while (fast->next != NULL){
			fast = fast->next;
			count++;
			if (count > k) slow = slow->next;
		}
		fast->next = head;
		head = slow->next;
		slow->next = NULL;
		
		return head;
	}
};

int main(){
	return 0;
}