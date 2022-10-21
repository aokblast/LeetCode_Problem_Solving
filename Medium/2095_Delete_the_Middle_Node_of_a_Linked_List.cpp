//
//Runtime 1178
//Memory Usage 294.9

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
    ListNode* deleteMiddle(ListNode* head) {
        int sz = 0;
        ListNode *trav = head;
        while(trav)
            trav = trav->next, sz++;
        
        ListNode *tmp = new ListNode();
        tmp->next = head;
        trav = tmp;
        
        int mid = (sz) / 2;
        
        while(mid) 
            --mid, trav = trav->next;
        trav->next = trav->next->next;
        return tmp->next;
    }
};