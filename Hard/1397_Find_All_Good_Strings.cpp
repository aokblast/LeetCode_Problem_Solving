//kmp
//Runtime 80
//Memory Usage 6.5

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {

public:
    ListNode *reverse(ListNode *head, ListNode *tail){
        ListNode *pre = tail;
        while(head != tail){
            ListNode *t = head->next;
            head->next = pre;
            pre = head;
            head = t;
        }
        return pre;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *trav = head;
        for(int i = 0; i < k; ++i){
            if(!trav) return head;
            trav = trav->next;
        }
        ListNode *newhead = reverse(head, trav);
        head->next = reverseKGroup(trav, k);
        return newhead;
    }
};
