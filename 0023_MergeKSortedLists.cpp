/*
23.合并K个有序链表
合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:
输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6

作者:syt
日期：2018-12-06

思路：将所有链表的数据取出来，排序建立新的链表
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return NULL;
        vector<int> data;
        for(int i = 0; i < lists.size(); ++i)
        {
            ListNode* tmp = lists[i];
            while(tmp)
            {
                data.push_back(tmp->val);
                tmp = tmp->next;
            }     
        }
        sort(data.begin(), data.end());
        
        ListNode* newHead = new ListNode(-1);
        ListNode* cur = newHead;
        for(int i = 0; i < data.size(); ++i)
        {
            ListNode* node = new ListNode(data[i]);
            cur->next = node;
            cur = cur->next;
        }
        return newHead->next;
    }
};