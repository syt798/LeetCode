/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* prev = head;
        ListNode* curr = head->next;
        while(curr != NULL)
        {
            if(prev->val == curr->val)
            {
                prev->next = curr->next;
            }
            else
                prev = prev->next;
            
            curr = curr->next;
        }
        
        return head;
    }
};