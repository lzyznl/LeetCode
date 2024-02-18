#include <iostream>
#include <vector>
using namespace std;

int find(vector<int>& vt,int x){
    int root = x;
    while(vt[root]>=0){
        root=vt[root];
    }
    while(x!=root){
        int node = vt[x];
        vt[x]=root;
        x=node;
    }
    return root;
}
//路径压缩
void unions(vector<int>& vt,int index1,int index2){
    int root1=find(vt,index1);
    int root2=find(vt,index2);
    if(root1==root2){
        return ;
    }
    if(vt[root1]<vt[root2]){
        //root1是大树，root2是小树
        vt[root1]+=vt[root2];
        vt[root2]=root1;
    }else{
        vt[root2]+=vt[root1];
        vt[root1]=root2;
    }
}

int findCircleNum(vector<vector<int>> &isConnected)
{
    int size = isConnected.size();
    vector<int> vt(size,-1);
    for(int i=0;i<isConnected.size();++i){
        for(int j=0;j<isConnected[i].size();++j){
            if(i!=j&&isConnected[i][j]==1){
                unions(vt,i,j);
            }
        }
    }
    int res = 0;
    for(int i=0;i<vt.size();++i){
        if(vt[i]<=-1){
            res++;
        }
    }
    return res;
}