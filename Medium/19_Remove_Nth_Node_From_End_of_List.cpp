//
//Runtime 4
//Memory Usage 10.8

class Solution {

	ListNode *arr[30];

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
 		    int top = 0;
            ListNode* trav = head;
		   	while(trav != NULL){
				arr[top++] = trav;
				trav = trav->next;
			}
			if(top == n) return head->next;
			else{
				arr[top - n - 1]->next = arr[top - n + 1];
				return head;
			}
    }
};
