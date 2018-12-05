/*
653.两数之和IV-输入BST
给定一个二叉搜索树和一个目标结果，如果 BST 中存在两个元素且它们的和等于给定的目标结果，则返回 true。

案例 1:
输入: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9
输出: True
 

案例 2:
输入: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28
输出: False

作者:syt
日期：2018-12-03

思路：中序遍历数，将数据存储到 vector 中，从vector 中查找是否有两个数的和为 target
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
    vector<int> data;
    void inOrder(TreeNode* root)
    {
        if(root)
        {
            inOrder(root->left);
            data.push_back(root->val);
            inOrder(root->right);
        }
    }
    bool findTarget(TreeNode* root, int k) {
        if(root)
        {
            inOrder(root);
            for(int i = 0; i < data.size(); ++i)
            {
                if(k-data[i] == data[i])
                    continue;
                vector<int>::iterator iter = find(data.begin(), data.end(), k-data[i]);
                if(iter != data.end())
                    return true;
            }
        }
        return false;
    }
};