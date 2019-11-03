/*
21.合并两个有序链表
将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：
输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4

作者:syt
日期：2018-12-05

思路：建立一个新的链表，两个指针分别指向两个链表的头节点，比较两个节点的大小，将值小的节点加入到新的链表中去，指针后移，以此类推，直到达到链表的结尾
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        
        ListNode* head = new ListNode(-1);
        ListNode* tmp = head;
        while(l1 || l2)
        {
            if(l1 == NULL)
            {
                ListNode* node = new ListNode(l2->val);
                tmp->next = node;
                l2 = l2->next;
            }
            else if(l2 == NULL)
            {
                ListNode* node = new ListNode(l1->val);
                tmp->next = node;   
                l1 = l1->next;
            }
            else if(l1->val >= l2->val)
            {
                ListNode* node = new ListNode(l2->val);
                tmp->next = node;   
                l2 = l2->next;
            }
            else
            {
                ListNode* node = new ListNode(l1->val);
                tmp->next = node;   
                l1 = l1->next;
            }
            tmp = tmp->next;
        }
        return head->next;
    }
};