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

void dfs(Node* root,vector<int>& vt){
    if(root==nullptr){
        return ;
    }
    vt.push_back(root->val);
    for(int i=0;i<root->children.size();++i){
        dfs(root->children[i],vt);
    }
}

//树的先根遍历
vector<int> preorder(Node *root)
{
    vector<int> vt;
    dfs(root,vt);
    return vt;
}