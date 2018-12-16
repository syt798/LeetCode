/*
958.二叉树的完全性检验

示例 1：
输入：[1,2,3,4,5,6]
输出：true
解释：最后一层前的每一层都是满的（即，结点值为 {1} 和 {2,3} 的两层），且最后一层中的所有结点（{4,5,6}）都尽可能地向左。

示例 2：
输入：[1,2,3,4,5,null,7]
输出：false
解释：值为 7 的结点没有尽可能靠向左侧。

作者：syt
日期：2018-12-16

思路：取出每一层的节点，判断是否满足完全二叉树
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
    bool isCompleteTree(TreeNode* root) {
        if(!root)
            return true;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            bool flag = false;
            bool end = true;
            bool isVal = false;
            for(int i = 0; i < n; ++i)
            {
                TreeNode* node = q.front();
                q.pop();
                if(!node)
                {
                    flag = true;
                }
                else
                {
                    if(flag)
                        return false;
                    end = false;
                }               
                
                if(node)
                {
                    if(node->left)
                    {
                        q.push(node->left);
                        isVal = true;

                    }
                    else
                        q.push(NULL);
                    
                    if(node->right)
                    {
                        q.push(node->right);
                        isVal = true;

                    }
                    else
                        q.push(NULL);                    
                     
                }
                else
                {
                    q.push(NULL);
                    q.push(NULL);
                }              
                
            }
            if(end)
                break;
            if(flag && isVal)
                return false;
            
        }
        return true;
    }
};