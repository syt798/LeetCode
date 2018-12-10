/*
24.两两交换链表中的节点
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

示例:
给定 1->2->3->4, 你应该返回 2->1->4->3.

作者:syt
日期：2018-12-10
*/

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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* header = new ListNode(0);
        ListNode* p = header;
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        
        while(curr != NULL)
        {
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev->next = tmp;
            
            p->next = curr;
            
            p = prev;
            prev = tmp;
            curr = tmp ? tmp->next : NULL;
            
            
        }
        return header->next;
    }
};