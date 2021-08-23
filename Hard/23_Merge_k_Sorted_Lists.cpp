//priority queue
//Runtime 12
//Memory Usage 13.9

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> q;
        for(auto list : lists){
            while(list != NULL) q.push(list->val), list = list->next;
        }
        ListNode *ret, *cur;
        cur = ret = new ListNode(-1);
        while(!q.empty()){
            cur->next = new ListNode(q.top());
            cur = cur->next;
            q.pop();
        }
        return ret->next;
    }
};


