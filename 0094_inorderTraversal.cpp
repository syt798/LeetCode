/*
94.二叉树的中序遍历
给定一个二叉树，返回它的中序 遍历。
示例:
输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]

作者:syt
日期：2018-12-04
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

//非递归版本
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == NULL)
            return result;
        stack<TreeNode*> st;
        while(!st.empty() || root != NULL)
        {
            while(root != NULL)
            {
                st.push(root);
                root = root->left;
            }
            
            if(!st.empty())
            {
                root = st.top();
                st.pop();
                result.push_back(root->val);
                root = root->right;
            }
        }        
        
        return result;
    }
};


//递归版本
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(root, result);        
        return result;
    }
};