//
//Runtime 4
//Memory Usage 8.8

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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode *trav = head;
        int sz = 0;
        while(trav)
            trav = trav->next, ++sz;
        int rem = sz % k;
        sz /= k;
        vector<ListNode *>res;
        trav = head;
        ListNode *hd;
        while(trav){
            hd = trav;
            int lim = sz + (--rem >= 0) - 1;
            for(int i = 0; i < lim; ++i){
                trav = trav->next;
            }
            ListNode *tmp = trav->next;
            trav->next = nullptr;
            trav = tmp;
            res.push_back(hd);
        }
        while(res.size() < k)
            res.push_back(nullptr);
        return res;
    }
};