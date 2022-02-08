//
//Runtime 8
//Memory Usage 11.7
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
    
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *trav = head;
        while(trav && trav->next){
            ListNode *tmp = trav->next;
            while(tmp && trav->val == tmp->val ){
                tmp = tmp->next;
            }
            trav->next = tmp;
            trav = trav->next;
        }
        return head;
    }
};
