/*
109.有序链表转换二叉搜索树
给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。
本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
示例:
给定的有序链表： [-10, -3, 0, 5, 9],
一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：
      0
     / \
   -3   9
   /   /
 -10  5

作者:syt
日期：2018-12-04

思路：由于链表有序，将链表中的数据取出存储在vector 中，利用二分法的方式构建树

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* constructTree(vector<int>& data, int left, int right)
    {
        if(left > right)
            return NULL;
        int mid = (left + right)/2;
        TreeNode* root = new TreeNode(data[mid]);
        root->left = constructTree(data, left, mid-1);
        root->right = constructTree(data, mid+1, right);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL)
            return NULL;
        vector<int> data;
        while(head)
        {
            data.push_back(head->val);
            head = head->next;
        }
        return constructTree(data, 0, data.size() - 1);
                
    }
};