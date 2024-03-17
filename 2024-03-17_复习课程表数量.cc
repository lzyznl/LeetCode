#include <iostream>
#include <vector>
#include <queue>
using namespace std;


//拓扑排序
bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> edge;
    vector<int> inedge(numCourses,0);
    queue<int> que;
    edge.resize(numCourses);
    for(int i=0;i<prerequisites.size();++i){
        edge[prerequisites[i][1]].push_back(prerequisites[i][0]);
        inedge[prerequisites[i][0]]++;
    }
    //寻找当前入度为0的元素，加入到入度数组当中
    for(int i=0;i<inedge.size();++i){
        if(inedge[i]==0){
            que.push(i);
        }
    }
    int isvisited = 0;
    while(!que.empty()){
        isvisited++;
        int node = que.front();
        que.pop();
        for(int i=0;i<edge[node].size();++i){
            --inedge[edge[node][i]];
            if(!inedge[edge[node][i]]){
                que.push(i);
            }
        }
    }
    return isvisited==numCourses;
}