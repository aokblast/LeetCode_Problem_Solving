//method 1(100, 57,52)

struct ListNode* reverseList(struct ListNode* head){
    if(head==NULL || head->next == NULL) return head;
    struct ListNode *prev;
    struct ListNode *curr = head;
    while (curr != NULL) {
        struct ListNode *tmp = curr->next;
        curr->next=prev;
        prev=curr;
        curr = tmp;
        if(prev == head) prev->next =NULL;
    }
    return prev;
}

// method 2(100, 6.6)

struct ListNode* reverseList(struct ListNode* head) {
    if (head==NULL || head->next == NULL) return head;
    struct ListNode *tmp = reverseList(head->next);
    head->next->next = head;
    head->next=NULL;
    return tmp;
}