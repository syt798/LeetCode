/*
897.递增顺序查找树
给定一个树，按中序遍历重新排列树，使树中最左边的结点现在是树的根，并且每个结点没有左子结点，只有一个右子结点。
示例 ：
输入：[5,3,6,2,4,null,8,1,null,null,null,7,9]

       5
      / \
    3    6
   / \    \
  2   4    8
 /        / \ 
1        7   9

输出：[1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
 1
  \
   2
    \
     3
      \
       4
        \
         5
          \
           6
            \
             7
              \
               8
                \
                 9  

作者:syt
日期：2018-12-04

思路：中序遍历树，将数据存储到vector中，修改节点的指向
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
    void inorder(TreeNode* root, vector<TreeNode*>& data)
    {
        if(root)
        {
            inorder(root->left, data);
            data.push_back(root);
            inorder(root->right, data);
        }
    }
    TreeNode* increasingBST(TreeNode* root) {
        if(root == NULL)
            return NULL;
        vector<TreeNode*> data;
        inorder(root, data);
        int i = 0;
        for(; i < data.size() - 1; ++i)
        {
            data[i]->left = NULL;
            data[i]->right = data[i+1];
        }
        data[i]->left = NULL;
        data[i]->right = NULL;
        return data[0];
    }
};