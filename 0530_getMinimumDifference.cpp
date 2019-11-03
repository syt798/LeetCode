/*
530.二叉搜索树的最小绝对差
给定一个所有节点为非负值的二叉搜索树，求树中任意两节点的差的绝对值的最小值。

示例 :
输入:

   1
    \
     3
    /
   2

输出:
1

解释:
最小绝对差为1，其中 2 和 1 的差的绝对值为 1（或者 2 和 3）。

作者:syt
日期：2018-12-06

思路：中序遍历二叉搜索树，中序遍历是有序数组，比较相邻两个数的差最小
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
    
    void inorder(TreeNode* root, vector<int>& data)
    {
        if(root)
        {
            inorder(root->left, data);
            data.push_back(root->val);
            inorder(root->right, data);
        }
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> data;
        inorder(root, data);
        int result = data[data.size()-1] - data[0];
        for(int i = 0; i < data.size()-1; ++i)
        {
            int tmp = data[i+1] - data[i];
            if(result > tmp)
                result = tmp;
        }
        return result;
    }
};