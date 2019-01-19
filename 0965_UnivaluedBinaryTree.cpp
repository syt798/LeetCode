/*
965.单值二叉树
如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树。
只有给定的树是单值二叉树时，才返回 true；否则返回 false。

示例 1：
输入：[1,1,1,1,1,null,1]
输出：true

示例 2：
输入：[2,2,2,5,2]
输出：false

作者：syt
日期：2019-01-19
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
    bool isUnival(TreeNode* root, int val)
    {
        if(root)
        {
            if(root->val != val)
                return false;
            return isUnival(root->left, val) && isUnival(root->right, val);
        }
        return true;
    }
    bool isUnivalTree(TreeNode* root) {
        if(!root)
            return false;
        int val = root->val;
        return isUnival(root, val);
    }
};