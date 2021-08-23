//std::sort
//Runtime 80 
//Memory Usage 30.3
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
    ListNode* sortList(ListNode* head) {
        vector<int> vals;
        ListNode *trav = head;
        while(trav){
            vals.push_back(trav->val);
            trav = trav->next;
        }
        sort(vals.begin(), vals.end());
        int i = 0;
        trav = head;
        while(trav){
            trav->val = vals[i++];
            trav = trav->next;
        }
        return head;
    }
};
//qsort
//Runtime 1452
//Memory Usage 30.2
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
    void qsort(ListNode *head, ListNode *end){
        if(head == end || head->next == end) return;
        ListNode *pivot = head;
        ListNode *left = head;
        ListNode *right = head->next;
        bool sorted = left->val <= right->val;
        while(right != end){
            if(pivot->val > right->val){
                swap(left->next->val, right->val);
                left = left->next;
            }
            if(sorted && right->next){
                sorted = sorted && right->val < right->next->val;
            }
            right = right->next;
        }
        if(sorted) return;
        swap(pivot->val, left->val);
        qsort(head, left);
        qsort(left->next, end);
    }
    ListNode* sortList(ListNode* head) {

        qsort(head, NULL);
        return head;
    }
};
