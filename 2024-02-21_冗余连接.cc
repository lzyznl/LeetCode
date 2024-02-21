#include <iostream>
#include <vector>
using namespace std;

/**
 * 并查集可以很好的用来解决图的连通性问题
*/

vector<int> result;

int find(vector<int>& bcset,int x){
    int root = x;
    while(bcset[root]>=0){
        root=bcset[root];
    }
    while(x!=root){
        int node = bcset[x];
        bcset[x]=root;
        x=node;
    }
    return root;
}

void unions(vector<int>& bcset,vector<int> pointVt){
    int point1 = pointVt[0];
    int point2 = pointVt[1];
    int root1 = find(bcset,point1);
    int root2 = find(bcset,point2);
    if(root1==root2){
        result.push_back(point1);
        result.push_back(point2);
        return ;
    }
    if(root1<root2){
        //root1为大树
        bcset[root1]+=bcset[root2];
        bcset[root2]=root1;
    }else{
        bcset[root2]+=bcset[root1];
        bcset[root1]=root2;
    }
}

vector<int> findRedundantConnection(vector<vector<int>> &edges)
{
    int size = edges.size();
    vector<int> BCSet(size+1,-1);
    for(int i=0;i<size;++i){
        unions(BCSet,edges[i]);
    }
    return result;
}