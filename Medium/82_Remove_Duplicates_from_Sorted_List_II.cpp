//
//Runtime 4
//Memory Usage 11.1
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
        if(!trav || !trav->next) return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *pre = dummy;
        while(pre->next){
            ListNode *now = pre->next;
            while(now->next && now->val == now->next->val) now = now->next;
            if(now == pre->next){
                pre = pre->next;
            }else{
                pre->next = now->next;
            }
        }
        return dummy->next;
    }
};
