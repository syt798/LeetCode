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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL)
            return result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            vector<int> res;
            for(int i = 0; i < n; i++)
            {
                TreeNode* tn = q.front();
                q.pop();
                res.push_back(tn->val);
                if(tn->left)
                    q.push(tn->left);
                if(tn->right)
                    q.push(tn->right);
            }
            result.push_back(res);
        }
        
        return result;
    }
};