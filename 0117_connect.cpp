/*
117.填充同一层的兄弟节点II
给定一个二叉树
struct TreeLinkNode {
  TreeLinkNode *left;
  TreeLinkNode *right;
  TreeLinkNode *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
初始状态下，所有 next 指针都被设置为 NULL。

说明:
你只能使用额外常数空间。
使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。
示例:

给定二叉树，

     1
   /  \
  2    3
 / \    \
4   5    7
调用你的函数后，该二叉树变为：

     1 -> NULL
   /  \
  2 -> 3 -> NULL
 / \    \
4-> 5 -> 7 -> NULL


作者:syt
日期：2018-12-03

思路：思路同 题116
*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL)
            return;
        queue<TreeLinkNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size(); 
            TreeLinkNode* pre = NULL;
            TreeLinkNode* cur = NULL;
            for(int i = 0; i < n; ++i)
            {
                if(pre == NULL)
                    pre = q.front();
                else
                {
                    cur = q.front();
                    pre->next = cur;
                    pre = pre->next;
                }
                TreeLinkNode* tmp = q.front();
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
                q.pop();
                
                
            }
            pre->next = NULL;
        }
        
    }
};