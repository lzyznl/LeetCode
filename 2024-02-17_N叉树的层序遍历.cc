#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

vector<vector<int>> levelOrder(Node *root)
{
    queue<Node *> que;
    vector<vector<int>> vt;
    if (root == nullptr)
    {
        return vt;
    }
    que.push(root);
    while (!que.empty())
    {
        int size = que.size();
        vector<int> subVt;
        while (size--)
        {
            Node *node = que.front();
            que.pop();
            for (int i = 0; i < node->children.size(); ++i)
            {
                if (node->children[i] != nullptr)
                {
                    que.push(node->children[i]);
                }
            }
            subVt.push_back(node->val);
        }
        vt.push_back(subVt);
    }
    return vt;
}