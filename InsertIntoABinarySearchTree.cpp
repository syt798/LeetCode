/*
701.二叉搜索树中的插入操作
给定二叉搜索树（BST）的根节点和要插入树中的值，将值插入二叉搜索树。 返回插入后二叉搜索树的根节点。 保证原始二叉搜索树中不存在新值。
注意，可能存在多种有效的插入方式，只要树在插入后仍保持为二叉搜索树即可。 你可以返回任意有效的结果。

例如, 
给定二叉搜索树:
        4
       / \
      2   7
     / \
    1   3
和 插入的值: 5
你可以返回这个二叉搜索树:

         4
       /   \
      2     7
     / \   /
    1   3 5
或者这个树也是有效的:

         5
       /   \
      2     7
     / \   
    1   3
         \
          4

思路：查找要插入的位置，用 pre 保存要插入节点的父节点，在pre的左子树或右子树插入节点

作者:syt
日期：2018-11-23
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
    
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL)
        {
            root = new TreeNode(val);
            return root;
        }
        TreeNode* tmp = root;
        TreeNode* pre = root;
        TreeNode* newNode = new TreeNode(val);
                
        while(tmp)
        {
            pre = tmp;
            if(tmp->val > val)
            {
                tmp = tmp->left;
            }
            else
                tmp = tmp->right;
        }
        
        if(pre->val > val)
            pre->left = newNode;
        else
            pre->right = newNode;
        
        return root;      
        
    }
};