#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
	ListNode *detectCycle(ListNode *head){
		if (!head) return NULL;
		if (!head->next) return NULL;
			
		int m1step = 0, m2step = 0, count = 0;
		ListNode *pfast = head->next->next, *pslow = head->next;
		
		while (pfast && pfast->next) {
			count++;
			if (pfast == pslow) {
				if (m1step == 0) m1step = count;
				else if (m2step == 0) {
					m2step = count;
					break;
				}
			}
			pfast = pfast->next->next;
			pslow = pslow->next;
		}
		
		if (!pfast || !pfast->next) return NULL;
		
		count = m2step - m1step;	
		pfast = head;
		pslow = head;
		while (count > 0) {
			pfast = pfast->next;
			count--;
		}
		while (pslow != pfast) {
			pslow = pslow->next;
			pfast = pfast->next;
		}
		return pslow;
	}
};

ListNode* makeList(int n, int x) {
	ListNode *head = NULL, *tail = NULL;
	for (int i = 1; i <= n; ++i) {
		if (!head) {
			head = new ListNode(i);
			tail = head;
		}else{
			ListNode *node = new ListNode(i);
			tail->next = node;
			tail = node;
		}	
	}
	if (x == -1) return head;
	
	ListNode *tmp = head;
	while (tmp->val != x) tmp = tmp->next;
	tail->next = tmp;
	return head;
}

int main(){
	int n, x;
	cin >> n >> x;
	ListNode *head = makeList(n, x);
	cout << "make over" << endl;
	Solution sc;
	ListNode *node = sc.detectCycle(head);
	if (!node) cout << "no cycle" << endl;
	else cout << "cycle start at: " << node->val << endl;
	return 0;
}