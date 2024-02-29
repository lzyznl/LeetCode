#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int flag=0;

void dfs(vector<vector<int>>& graph,vector<bool>& isVisited,vector<int>& result,vector<bool>& nowVisited,int u){
    isVisited[u]=true;
    nowVisited[u]=true;
    for(int i=0;i<graph[u].size();++i){
        if(nowVisited[graph[u][i]]){
            flag=1;
            return ;
        }
        if(!isVisited[graph[u][i]]){
            dfs(graph,isVisited,result,nowVisited,graph[u][i]);
        }                                          
    }
    nowVisited[u]=false;
    result.push_back(u);
}


vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<int> result;
    vector<vector<int>> graph;
    vector<bool> isVisited(numCourses,false);
    vector<bool> nowVisited(numCourses,false);
    graph.resize(numCourses);
    for(auto& info:prerequisites){
        graph[info[1]].push_back(info[0]);
    }
    //对图进行深度优先遍历
    for(int i=0;i<isVisited.size();++i){
        if(!isVisited[i]){
            dfs(graph,isVisited,result,nowVisited,i);
        }
    }
    reverse(result.begin(),result.end());
    vector<int> emptyVt;
    return flag==0?result:emptyVt;
}