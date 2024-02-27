#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

unordered_map<Node*,Node*> map;

Node* dfs(Node* node){
    if(node==nullptr){
        return node;
    }
    if(map.find(node)!=map.end()){
        return map[node];
    }

    Node* newNode = new Node(node->val);
    map[node]=newNode;
    for(Node* n:node->neighbors){
        newNode->neighbors.push_back(dfs(n));
    }
    return newNode;
}

Node *cloneGraph(Node *node)
{
    return dfs(node);
}