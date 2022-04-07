//
//Runtime 560
//Memory Usage 180.2

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
    ListNode* swapNodes(ListNode* head, int k) {
        int n = 0;
        ListNode *l = head;
        --k;
        while(k--)
            l = l->next;
        ListNode *tmp = l, *r = head;
        while(tmp->next)
            r = r->next, tmp = tmp->next;
        swap(l->val, r->val);
        return head;
    }
};



