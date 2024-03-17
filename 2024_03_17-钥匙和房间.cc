#include <iostream>
#include <vector>
using namespace std;


void dfs(vector<vector<int>>& edge,vector<bool>& isVisited,int v,int& visitedCount){
    isVisited[v]=true;
    visitedCount++;
    for(int i=0;i<edge[v].size();++i){
        if(!isVisited[edge[v][i]]){
            dfs(edge,isVisited,edge[v][i],visitedCount);
        }
    }
}

//构建邻接矩阵，判断图的连通性
bool canVisitAllRooms_dfs(vector<vector<int>> &rooms)
{
    const int inf = INT32_MAX/2;
    int n = rooms.size();
    vector<vector<int>> edge;
    edge.resize(n);
    vector<bool> isVisited(n,false);
    for(int i=0;i<rooms.size();++i){
        for(int j=0;j<rooms[i].size();++j){
            edge[i].push_back(rooms[i][j]);
        }
    }
    int isVisitedCount = 0;
    dfs(edge,isVisited,0,isVisitedCount);
    return isVisitedCount==n;
}