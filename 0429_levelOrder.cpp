/*
429.N叉树的层序遍历
给定一个 N 叉树，返回其节点值的层序遍历。 (即从左到右，逐层遍历)。

返回其层序遍历:

[
     [1],
     [3,2,4],
     [5,6]
]
说明:

树的深度不会超过 1000。
树的节点总数不会超过 5000。

作者:syt
日期：2018-11-22
*/

/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        queue<Node*> q;
        if(root)
        {
            q.push(root);
            while(!q.empty())
            {
                int n = q.size();
                vector<int> tmp;
                for(int i = 0; i < n; ++i)
                {
                    Node* node = q.front();
                    q.pop();
                    for(int j = 0; j < node->children.size(); ++j)
                        if(node->children[j])
                            q.push(node->children[j]);
                    tmp.push_back(node->val);
                }
                result.push_back(tmp);
            }
        }
        return result;
    }
};