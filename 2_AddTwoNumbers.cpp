/*
2.两数相加
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

作者:syt
日期：2018-11-29

思路：遍历链表，注意链表是否到链表尾
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        ListNode* newHead = new ListNode(-1);
        ListNode* cur = newHead;
        int carry = 0;
        while(l1 && l2)
        {
            int val = l1->val + l2->val + carry;
            carry = val/10;
            ListNode* tmp = new ListNode(val%10);
            cur->next = tmp;
            cur = tmp;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1)
        {
            int val = l1->val + carry;
            carry = val/10;
            ListNode* tmp = new ListNode(val%10);
            cur->next = tmp;
            cur = tmp;
            l1 = l1->next;
        }
        while(l2)
        {
            int val = l2->val + carry;
            carry = val/10;
            ListNode* tmp = new ListNode(val%10);
            cur->next = tmp;
            cur = tmp;
            l2 = l2->next;
        }        
        
        if(carry > 0)
        {
            ListNode* tmp = new ListNode(carry);
            cur->next = tmp;
            cur = tmp;
        }
        
        return newHead->next;
    }
};