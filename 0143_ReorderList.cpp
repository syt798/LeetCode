/*
143.重排链表
给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例 1:
给定链表 1->2->3->4, 重新排列为 1->4->2->3.

示例 2:
给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.

作者：syt
日期：2018-12-12
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
    void reorderList(ListNode* head) {
        vector<ListNode*> data;
        while(head)
        {
            data.push_back(head);
            head = head->next;
        }
        ListNode* newHead = new ListNode(-1);
        ListNode* tmp = newHead;
        int start = 0, end = data.size()-1;
        while(start <= end)
        {
            if(start == end)
                tmp->next = data[start];
            else
            {
                tmp->next = data[start];
                tmp = tmp->next;
                tmp->next = data[end];
            }
            tmp = tmp->next;
            ++start;
            --end;
        }
        tmp->next = NULL;
        head = newHead->next;
    }
};