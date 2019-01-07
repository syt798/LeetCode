/*
430.扁平化多级双向链表
您将获得一个双向链表，除了下一个和前一个指针之外，它还有一个子指针，可能指向单独的双向链表。这些子列表可能有一个或多个自己的子项，依此类推，生成多级数据结构，如下面的示例所示。
扁平化列表，使所有结点出现在单级双链表中。您将获得列表第一级的头部。
 
示例:
输入:
 1---2---3---4---5---6--NULL
         |
         7---8---9---10--NULL
             |
             11--12--NULL

输出:
1-2-3-7-8-11-12-9-10-4-5-6-NULL


作者:syt
日期：2019-01-07
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        if(!head)
            return NULL;
        Node* node = head;
        stack<Node*> s;
        while(node)
        {
            if(node->child)
            {
                s.push(node->next);
                node->next = node->child;
                if(node->next)
                    node->next->prev = node;
                node->child = NULL;
            }
            else if(node->next == NULL && !s.empty())
            {
                node->next = s.top();
                s.pop();
                if(node->next)
                    node->next->prev = node;
            }
            node = node->next;
        }
        return head;
        
    }
};