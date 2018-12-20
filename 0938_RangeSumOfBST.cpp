/*
938.二叉树的范围和
给定二叉搜索树的根结点 root，返回 L 和 R（含）之间的所有结点的值的和。
二叉搜索树保证具有唯一的值。

示例 1：
输入：root = [10,5,15,3,7,null,18], L = 7, R = 15
输出：32

示例 2：
输入：root = [10,5,15,3,7,13,18,1,null,6], L = 6, R = 10
输出：23

作者：syt
日期：2018-12-19

思路：中序遍历，判断节点值，累加sum
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
    void inOrderTraversal(TreeNode* root, int L, int R, int& sum)
    {
        if(root)
        {
            inOrderTraversal(root->left, L, R, sum);
            if(root->val >= L && root->val <= R)
                sum += root->val;
            inOrderTraversal(root->right, L, R, sum);
        }
    }
    int rangeSumBST(TreeNode* root, int L, int R) {
        int sum = 0;
        inOrderTraversal(root, L, R, sum);
        return sum;
    }
};