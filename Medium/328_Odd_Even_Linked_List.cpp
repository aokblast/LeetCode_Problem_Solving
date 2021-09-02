//
//Runtime 11
//Memory Usage 10.5
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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *even = head, *odd = head->next, *odd_next = head->next;
        while(odd && odd->next){
            even = even->next = odd->next;
            odd = odd->next = even->next;
        }
        even->next = odd_next;
        return head;
    }
};
