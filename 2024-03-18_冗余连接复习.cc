#include <iostream>
#include <vector>

using namespace std;

int lastIndex = 0;

int find(vector<int>& vt,int v){
    int root = v;
    while(vt[root]>=0){
        root=vt[root];
    }
    while(v!=root){
        int temp = vt[v];
        vt[v]=root;
        v=temp;
    }
    return root;
}

void unions(vector<int>& vt,int v1,int v2,int index){
    int v1_root = find(vt,v1);
    int v2_root = find(vt,v2);
    if(v1_root==v2_root){
        lastIndex = index;
    }
    else if (v1_root<=v2_root){
        vt[v1_root]+=vt[v2_root];
        vt[v2_root]=v1_root;
    }else{
        vt[v2_root]+=vt[v1_root];
        vt[v1_root]=v2_root;
    }
}

vector<int> findRedundantConnection(vector<vector<int>> &edges)
{
    int n = edges.size();
    vector<int> vt(n+1,-1);
    for(int i=0;i<edges.size();++i){
        unions(vt,edges[i][0],edges[i][1],i);
    }
    return edges[lastIndex];
}