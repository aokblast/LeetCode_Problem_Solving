//
//Runtime 18
//Memory Usage 11.4

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
    ListNode* removeZeroSumSublists(ListNode* head) {
        
        ListNode *dump = new ListNode(0, head), *trav = dump;
        int sum = 0;
        
        unordered_map<int, ListNode *> mp;
        
        for(; trav ;trav = trav->next)
            mp[sum += trav->val] = trav;
        
        sum = 0;
        trav = dump;
        
        for(; trav; trav = trav->next)
            trav->next = mp[sum += trav->val]->next;
        
        return dump->next;
    }
};