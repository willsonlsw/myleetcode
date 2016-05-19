#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;


struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x), next(NULL) {}
};


class Solution{
public:
	ListNode* removeNthFromEnd_V1(ListNode* head, int n){
		vector<ListNode*> links;
		ListNode *ptr = head;
		while (ptr != NULL){
			links.push_back(ptr);
			ptr = ptr->next;
		}
		int idx = links.size() - n;
		if (idx == 0) return head->next;
		else if (n == 1){
			links[idx - 1]->next = NULL;
			return head;
		}else{
			links[idx - 1]->next = links[idx + 1];
			return head;
		}
	}

	ListNode* removeNthFromEnd(ListNode* head, int n){
		ListNode *ptr1, *ptr2;
		ptr1 = head; 
		ptr2 = head;
		int count = 0;
		while (ptr1 != NULL){
			ptr1 = ptr1->next;
			if (count > n) ptr2 = ptr2->next;
			count += 1;
		}
		ptr2->next = ptr2->next->next;
		return head;
	}
};


int main(){
	int nums[] = {1, 2, 3, 4, 5};
	int N = 5;
	int n = sizeof(nums) / sizeof(int);
	ListNode *head, *ptr;
	for (int i = 0; i < n; ++i){
		if (head == NULL){
			head = (ListNode*)malloc(sizeof(ListNode));
			head->val = nums[i];
			ptr = head;
			continue;
		}
		ListNode *node = (ListNode*)malloc(sizeof(ListNode));
		node->val = nums[i];
		node->next = NULL;
		ptr->next = node;
		ptr = node;
	}
	
	Solution sc;
	ListNode *newHead = sc.removeNthFromEnd(head, N);

	ptr = newHead;
	while (ptr != NULL){
		cout << ptr->val << ' ';
		ptr = ptr->next;
	}
	cout << endl;

	return 0;
}
