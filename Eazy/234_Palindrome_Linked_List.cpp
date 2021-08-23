//stack
//Runtime 228 
//Memory Usgae 128.4 
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
    bool isPalindrome(ListNode* head) {
        ListNode *trav = head;
        stack<ListNode *> s;
        while(trav){
            s.push(trav);
            trav = trav->next;
        }
        int size = s.size();
        int cnt = 0;
        while(cnt < (size + 1) / 2){
            ListNode *top  = s.top(); s.pop();
            if(top->val != head->val) return false;
            ++cnt;
            head = head->next;
            
        }
        return true;
    }
};

//Reverse
//Runtime 208
//Memory Usage 118
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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode *slow = head, *fast = head;
        while(fast->next && fast->next->next) slow = slow->next, fast = fast->next->next;
        ListNode *pre = head, *last = slow->next;
        while(last->next){
            ListNode *tmp = last->next;
            last->next  = tmp->next;
            tmp->next = slow->next;
            slow->next = tmp;
        }
        while (slow->next) {
            slow = slow->next;
            if (pre->val != slow->val) return false;
            pre = pre->next;
        }
        return true;
    }
};
