/*
145.二叉树的后序遍历
给定一个二叉树，返回它的 后序 遍历。
示例:
输入: [1,null,2,3]  
   1
    \
     2
    /
   3 

输出: [3,2,1]

作者:syt
日期：2018-12-06
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
//非递归
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(root == NULL)
            return ret;
        TreeNode* pre = NULL;
        stack<TreeNode*> ms;
        while(root != NULL || !ms.empty())
        {
            while(root)
            {
                ms.push(root);
                root = root->left;
            }
            
            root = ms.top();
            if(root->right == NULL || root->right == pre)
            {
                ret.push_back(root->val);
                pre = root;
                ms.pop();
                root = NULL;
            }
            else
                root = root->right;
            
        }
        return ret;
    }
};


//递归
class Solution {
public:
    void postorder(TreeNode* root, vector<int>& data)
    {
        if(root)
        {
            postorder(root->left, data);
            postorder(root->right, data);
            data.push_back(root->val);
        }
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        postorder(root, ret);
        return ret;
    }
};