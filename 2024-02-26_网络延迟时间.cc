#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//dijkstra算法
int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    const int inf = INT32_MAX/2;
    vector<vector<int>> graph (n,vector<int>(n,inf));
    //建立邻接矩阵
    for(auto& time:times){
        graph[time[0]-1][time[1]-1]=time[2];
    }
    //建立dist数组
    vector<int> dist(n,inf);
    //建立判断数组
    vector<bool> isVisited(n,false);
    //初始化开始顶点到其它顶点之间的距离
    for(int i=0;i<n;++i){
        dist[i]=graph[k-1][i];
    }
    //进行初始化起始节点
    dist[k-1]=0;
    isVisited[k-1]=true;
    //遍历剩余n-1个顶点即可
    for(int i=0;i<n-1;++i){
        int min = inf;
        int index = -1;
        for(int j=0;j<n;++j){
            if(!isVisited[j]&&dist[j]<min){
                min=dist[j];
                index=j;
            }
        }
        //没有找到最小节点，说明不连通
        if(index==-1){
            return -1;
        }
        isVisited[index]=true;
        //使用此节点跟新其它节点的值
        for(int j=0;j<n;++j){
            if(!isVisited[j]&&graph[index][j]+dist[index]<dist[j]){
                dist[j]=graph[index][j]+dist[index];
            }
        }
    }
    sort(dist.begin(),dist.end());
    return dist[n-1]==inf?-1:dist[n-1];
}