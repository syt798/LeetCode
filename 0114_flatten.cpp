//将树的节点前序取出来，重新排列

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
    void preOrder(TreeNode *root, vector<TreeNode*> &nodes) {
        if (root) {
            nodes.push_back(root);
            preOrder(root->left, nodes);
            preOrder(root->right, nodes);
        }
    }
    void flatten(TreeNode* root) {
        vector<TreeNode*> nodes;
        preOrder(root, nodes);
        TreeNode *tmp = root;
        for (int i = 1; i < nodes.size(); ++i) {
            tmp->left = NULL;
            tmp->right = nodes[i];
            tmp = tmp->right;
        }
    }
};