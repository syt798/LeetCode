/*
445.两数相加II
给定两个非空链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储单个数字。将这两数相加会返回一个新的链表。
你可以假设除了数字 0 之外，这两个数字都不会以零开头。

示例:
输入: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
输出: 7 -> 8 -> 0 -> 7

作者:syt
日期：2018-12-12

思路：利用栈结构将链表中的数据取出，计算两个栈的和，建立新的链表
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
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        stack<int> st1;
        stack<int> st2;
        while(l1 || l2)
        {
            if(l1)
            {
                st1.push(l1->val);
                l1 = l1->next;  
            }
            if(l2)
            {
                st2.push(l2->val);
                l2 = l2->next;
            }
        }
        int carry = 0;
        stack<int> result;
        while(!st1.empty() || !st2.empty())
        {
            int x = 0, y = 0;
            if(!st1.empty())
            {
                x = st1.top();
                st1.pop();
            }
            if(!st2.empty())
            {
                y = st2.top();
                st2.pop();
            }
            result.push((x+y+carry)%10);
            carry = (x+y+carry)/10;
        }
        if(carry > 0)
            result.push(carry);
        
        ListNode* newHead = new ListNode(-1);
        ListNode* tmp = newHead;
        while(!result.empty())
        {
            int val = result.top();
            result.pop();
            ListNode* node = new ListNode(val);
            tmp->next = node;
            tmp = tmp->next;
        }
        
        return newHead->next;
        
    }
};