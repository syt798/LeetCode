/*
203.移除链表元素
删除链表中等于给定值 val 的所有节点。

示例:
输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5

作者:syt
日期：2018-12-04

思路：首先排除头结点是否和 val 值相同，对于头结点之后的节点，设置两个指针 cur和next，遍历链表修改指针的指向

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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL)
            return NULL;
        ListNode* tmp = head;
        while(tmp && tmp->val == val)
            tmp = tmp->next;
        head = tmp;
        if(head == NULL)
            return NULL;
        ListNode* cur = head;
        ListNode* next = head->next;
        while(next)
        {
            if(next->val == val)
            {
                next = next->next;
                cur->next = next;
            }
            else
            {
                cur = next;
                next = next->next;
            }
            
        }
        return head;
    }
};