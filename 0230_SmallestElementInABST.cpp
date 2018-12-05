/*
230.二叉搜索树中第k小的元素
给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。
说明：
你可以假设 k 总是有效的，1 ≤ k ≤ 二叉搜索树元素个数。

示例 1:
输入: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
输出: 1

示例 2:
输入: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
输出: 3
进阶：
如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 k 小的值，你将如何优化 kthSmallest 函数？

思路：二叉搜索树的中序遍历是有序的数组，中序遍历后取第k-1个

作者:syt
日期：2018-11-22
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
    void inOrderTraverse(TreeNode* root, vector<int>& data)
    {
       if(root)
       {
           inOrderTraverse(root->left, data);
           data.push_back(root->val);
           inOrderTraverse(root->right, data);
       }
    }
        
    int kthSmallest(TreeNode* root, int k) {
        vector<int> data;
        inOrderTraverse(root, data);
        return data[k-1];
    }
};