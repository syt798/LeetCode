/*
92.反转链表II
反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
说明:
1 ≤ m ≤ n ≤ 链表长度。

示例:
输入: 1->2->3->4->5->NULL, m = 2, n = 4
输出: 1->4->3->2->5->NULL

作者：syt
日期：2018-12-18
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
    
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m >= n || !head)
            return head;
        ListNode* cur = head;
        vector<int> data(1, 0);
        while(cur)
        {
            data.push_back(cur->val);
            cur = cur->next;
        }
        while(m <= n)
        {
            int swap = data[m];
            data[m] = data[n];
            data[n] = swap;
            ++m;
            --n;
        }
        ListNode* newHead = new ListNode(-1);
        ListNode* tmp = newHead;
        for(int i = 1; i < data.size(); ++i)
        {
            ListNode* node = new ListNode(data[i]);
            tmp->next = node;
            tmp = tmp->next;
        }
        
        return newHead->next;
    }
};