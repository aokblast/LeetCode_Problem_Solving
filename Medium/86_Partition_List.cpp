//
//Runtime 4
//Memory Usage 10.3
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
    ListNode* partition(ListNode* head, int x) {
        
        ListNode *dummy = new ListNode(-1);
        ListNode *trav = dummy;
        dummy->next = head;
        while(trav){
            ListNode *h = trav->next;
            ListNode *prev = trav;
            while(h && h->val >= x) prev = h, h = h->next;
            
            if(h == NULL) break;
            
            if(prev != trav){
                prev->next = h->next;
                h->next = trav->next;
                trav->next = h;
            }
            
            trav = trav->next;
            
        }
        return dummy->next;
    }
};
