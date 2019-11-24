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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > ret;
        if(root == NULL)
            return ret;
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            vector<int> vals;
            for(int i = 0; i < n; i++)
            {
                TreeNode* tmp = q.front();
                q.pop();
                vals.push_back(tmp->val);
                
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);

            }
            ret.push_back(vals);
            
        }
        
        reverse(ret.begin(), ret.end());
        return ret;
    }
};