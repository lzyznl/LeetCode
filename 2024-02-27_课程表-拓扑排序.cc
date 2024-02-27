#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

//拓扑排序
bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> edge;
    vector<int> inedge(numCourses,0);
    edge.resize(numCourses);
    for(auto& info:prerequisites){
        edge[info[1]].push_back(info[0]);
        ++inedge[info[0]];
    }
    //寻找入度为0的节点，加入入读数组当中
    queue<int> que;
    for(int i=0;i<inedge.size();++i){
        if(inedge[i]==0){
            que.push(i);
        }
    }
    //进行边的删除以及新入度为0节点的添加
    int isvisted = 0;
    while(!que.empty()){
        isvisted++;
        int node = que.front();
        que.pop();
        for(int v:edge[node]){
            --inedge[v];
            if(inedge[v]==0){
                que.push(v);
            }
        }
    }
    return isvisted==numCourses;
}