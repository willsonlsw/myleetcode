    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head, *ptr;
        while (l1 != NULL && l2 != NULL){
            ListNode *node = (ListNode*)malloc(ListNode);
            if (l1->val < l2->val) {
                node->val = l1->val;
                l1 = l1->next;
            }else{
                node->val = l2->val;
                l2 = l2->next;
            }
            
            if (head == NULL) {
                head = node;
                ptr = head;
            }else{
                ptr->next = node;
                ptr = node;
            }
        }
        
        if (l1 != NULL) ptr->next = l1;
        if (l2 != NULL) ptr->next = l2;
        
        return head;
    }