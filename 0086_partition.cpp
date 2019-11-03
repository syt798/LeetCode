/*
86.分割链表
给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
你应当保留两个分区中每个节点的初始相对位置。

示例:
输入: head = 1->4->3->2->5->2, x = 3
输出: 1->2->2->4->3->5

作者:syt
日期：2018-12-13
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
    ListNode* partition(ListNode* head, int x) {
        if(!head)
            return head;
        ListNode* less = new ListNode(-1);
        ListNode* more = new ListNode(-1);
        ListNode* lessTmp = less;
        ListNode* moreTmp = more;
        while(head)
        {
            ListNode* node = new ListNode(head->val);
            if(head->val >= x)
            {
                moreTmp->next = node;
                moreTmp = moreTmp->next;
            }
            else
            {
                lessTmp->next = node;
                lessTmp = lessTmp->next;
            }
            head = head->next;
        }
        lessTmp->next = more->next;
        
        return less->next;
    }
};