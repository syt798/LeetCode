/*
589.N叉树的前序遍历
给定一个 N 叉树，返回其节点值的前序遍历。

作者：syt
日期：2019-01-19
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
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
    vector<int> result;
    void pre(Node* root)
    {
        if(root == NULL)
            return;
        result.push_back(root->val);
        for(int i = 0; i < root->children.size(); ++i)
        {
            pre(root->children[i]);
        }
    }
    vector<int> preorder(Node* root) {
        pre(root);
        return result;
    }
};