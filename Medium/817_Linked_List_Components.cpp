//
//Runtime 39 
//Memory 21.5
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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> s;
        int res = 0;
        for(const int num : nums)
            s.insert(num);
        while(head){
            if(s.find(head->val) != s.end()){
                ListNode *ne = head->next;
                while(ne && s.find(ne->val) != s.end())
                      ne = ne->next;
                head = ne;
                ++res;
            }else{
                head = head->next;
            }
        }
        return res;
        
    }
};