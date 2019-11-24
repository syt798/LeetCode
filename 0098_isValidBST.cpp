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
    void traversal(TreeNode* root)
    {
        if(root == NULL)
            return;
        traversal(root->left);
        data.push_back(root->val);
        traversal(root->right);
    }
    bool isValidBST(TreeNode* root) {
        if(root == NULL)
            return true;
        traversal(root);
        bool result = true;
        for(int i = 0; i < data.size()-1; ++i)
        {
            if(data[i] >= data[i+1])
            {
                result = false;
                break;
            }
        }
        return result;
    }
};