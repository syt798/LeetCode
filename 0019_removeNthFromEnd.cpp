/*
19.删除链表的倒数第N个节点
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
示例：
给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.

作者:syt
日期：2018-12-07

思路：设置两个指针，pre 和 cur，pre指针先走 N 步，然后 cur 和 pre 同时向后移动，直到 pre到达尾节点，cur指向的节点就是要删除的节点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        
        ListNode* cur = head;
        ListNode* pre = head->next;
        
        while(n > 0 && pre != NULL)
        {
            pre = pre->next;
            n--;
        }
        if(pre == NULL && n > 0)
        {
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
            return head;
        }
        while(pre != NULL)
        {
            pre = pre->next;
            cur = cur->next;
        }
        ListNode* tmp = cur->next;
        cur->next = tmp->next;
        delete tmp;
        return head;
    }
};