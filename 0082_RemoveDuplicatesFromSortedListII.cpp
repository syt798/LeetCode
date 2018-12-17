/*
82.删除排序链表中的重复元素II
给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。

示例 1:
输入: 1->2->3->3->4->4->5
输出: 1->2->5

示例 2:
输入: 1->1->1->2->3
输出: 2->3

作者：syt
日期：2018-12-17
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* pre = NULL;
        ListNode* cur = head;
        ListNode* next = head->next;
        bool isequal = false;
        while(next)
        {
            if(cur->val == next->val)
            {
                next = next->next;
                isequal = true;
            }
            else
            {
                if(isequal)
                {
                    cur = next;
                    next = next->next;
                    isequal = false;
                }
                else
                {
                    if(pre == NULL)
                    {
                        head = cur;
                        pre = head;
                        cur = cur->next;
                        next = next->next;
                    }
                    else
                    {
                        pre->next = cur;
                        pre = pre->next;
                        cur = cur->next;
                        next = next->next;
                    }
                }
            }
        }
        if(pre)
        {
            if(isequal)
                pre->next = NULL;
            else
            {
                pre->next = cur;
                cur->next = NULL;
            }
        }
        else
        {
            if(isequal)
            {
                head = NULL;
            }
            else
                head = cur;
            
        }

        return head;
        
    }
};