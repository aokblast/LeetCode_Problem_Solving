//Monotonic stack
//Runtime 94
//Memory Usage 40.8

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
    vector<int> nextLargerNodes(ListNode* head) {
        stack<pair<int, int>> stk;
        
        ListNode *trav = head;
        int n = 0;
        
        for(; trav; trav = trav->next)
            ++n;
        vector<int> res(n);
        int idx = 0;
        for(;head; head = head->next){
            
            while(stk.size() && stk.top().first < head->val)
                res[stk.top().second] = head->val, stk.pop();
            
            stk.push({head->val, idx++});
            
        }
        return res;
    }
};