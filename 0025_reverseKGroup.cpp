/*
25.k个一组翻转链表
给出一个链表，每 k 个节点一组进行翻转，并返回翻转后的链表。
k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么将最后剩余节点保持原有顺序。

示例 :
给定这个链表：1->2->3->4->5
当 k = 2 时，应当返回: 2->1->4->3->5
当 k = 3 时，应当返回: 3->2->1->4->5

作者：syt
日期：2018-12-11

思路：利用 vector 存储 k 个节点的数据，如果节点数量等于 K 个，则vector 中数据翻转，否则则不变
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL)
            return head;
        vector<int> data;
        ListNode* newHead = new ListNode(-1);
        ListNode* headTmp = newHead;
        while(head)
        {
            int count = 1;
            while(count <= k && head)
            {
                data.push_back(head->val);
                count++;
                head = head->next;
            }
            if(count > k)
            {
                reverse(data.begin(), data.end());
            }
            for(int i = 0; i < data.size(); ++i)
            {
                ListNode* node = new ListNode(data[i]);
                headTmp->next = node;
                headTmp = headTmp->next;
            }
            vector<int>().swap(data);
        }
        return newHead->next;
    }
};