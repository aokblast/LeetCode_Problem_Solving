//
//Runtime 4
//Memory Usage 11.8
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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* trav = head;
        int size = 0;
        if(head == NULL) return head;
        
        while(trav->next != NULL){
            ++size;
            trav = trav->next;
        }
        ++size;
        
        if(size < 2 || k % size == 0) return head;
        trav->next = head;
        k %= size;
        
        k = size - k;
        trav = head;
        while(k > 1){
            trav = trav->next;
            --k;
        }
        ListNode *tmp = trav;
        trav = trav->next;
        ListNode* result = trav;
        tmp->next = NULL;

        return result;
        
    }
};
