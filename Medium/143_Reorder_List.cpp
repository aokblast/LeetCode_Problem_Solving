//stack
//Runtime 32
//Memory Usage 18.5
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
    void reorderList(ListNode* head) {
        stack<ListNode *> stk;
        ListNode *trav = head;
        int cnt = 0;
        while(trav){
            stk.push(trav);
            trav = trav->next;
            ++cnt;
        }
        --cnt;
        cnt /= 2;
        trav = head;
        while(cnt--){
            ListNode *tmp = stk.top();stk.pop();
            tmp->next = trav->next;
            trav->next = tmp;
            trav = trav->next->next;
            stk.top()->next = NULL;
        }
    }
};
