//
//Runtime 4
//Memory Usage 15.1

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *result = NULL;
        ListNode *begin = NULL;
        while(l1 != NULL || l2 != NULL){
            if(l1 == NULL || (l2 != NULL && l2->val <= l1->val)){
                ListNode *newNode = new ListNode(l2->val);
                if(result == NULL){
                    result = begin = newNode;
                    l2 = l2->next;
                }else {
                    begin->next = newNode;
                    begin = begin->next;
                    l2 = l2->next;
                }
            }else {
                ListNode *newNode = new ListNode(l1->val);
                if(result == NULL){
                    result = begin = newNode;
                    l1 = l1->next;
                }else {
                    begin->next = newNode;
                    begin = begin->next;
                    l1 = l1->next;
                }
            }
        }
        return result;
    }

};
