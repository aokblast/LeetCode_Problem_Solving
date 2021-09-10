//
//Runtime 24 
//Memory Usage 16.5
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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    ListNode *head;
    int size = 0;
    Solution(ListNode* _head) {
        
        head = _head;
        ListNode *trav = head;
        while(trav){
            ++size;
            trav = trav->next;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int t = rand() % size;
        ListNode *trav = head;
        while(t){
            --t;
            trav = trav->next;
        }
        return trav->val;
            
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
