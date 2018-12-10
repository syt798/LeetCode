/*
147.对链表进行插入排序
插入排序算法：
插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
重复直到所有输入数据插入完为止。

示例 1：
输入: 4->2->1->3
输出: 1->2->3->4

示例 2：
输入: -1->5->3->4->0
输出: -1->0->3->4->5

作者：syt
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
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode* tmpHead = head->next;
        head->next = NULL;
        while(tmpHead)
        {
            ListNode* cur = tmpHead;
            tmpHead = tmpHead->next;
            
            ListNode* p = NULL, *q = head;
            while(q && q->val <= cur->val)
            {
                p = q;
                q = q->next;
            }
            
            if(q == head)
            {
                head = cur;
            }
            else
            {
                p->next = cur;
            }
            cur->next = q;
        }
        return head;
    }
};