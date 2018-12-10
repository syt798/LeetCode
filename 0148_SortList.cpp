/*
148.排序链表
在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。

示例 1:
输入: 4->2->1->3
输出: 1->2->3->4

示例 2:
输入: -1->5->3->4->0
输出: -1->0->3->4->5

作者：syt
日期：2018-12-10

思路：取出数据，快排排序
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
    ListNode* sortList(ListNode* head) {
        vector<int> data;
        while(head)
        {
            data.push_back(head->val);
            head = head->next;
        }
        
        ListNode* newHead = new ListNode(-1);
        ListNode* tmp = newHead;
        sort(data.begin(), data.end());
        for(int i = 0; i < data.size(); ++i)
        {
            ListNode* node = new ListNode(data[i]);
            tmp->next = node;
            tmp = tmp->next;
        }
        return newHead->next;
    }
};