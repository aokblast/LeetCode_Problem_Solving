//
//Runtime 0
//Memory Usage 7.2
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
    ListNode* middleNode(ListNode* head) {
        int len = 0;
        ListNode *trav = head;
        while(trav) trav = trav->next, ++len;
        len /= 2;
        trav = head;
        while(len--){
            trav = trav->next;
        }
        return trav;
    }
};