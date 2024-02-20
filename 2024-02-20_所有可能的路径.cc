#include <iostream>
#include <vector>
using namespace std;

//主要还是考察图的深度优先搜索

//用来存储每条符合条件的路径
vector<vector<int>> result;
//用来存储符合条件的单条路径
vector<int> singlePath;

void DFS(vector<vector<int>>& graph,int v){
    if(v==graph.size()-1){
        result.push_back(singlePath);
        return ;
    }
    for(int i=0;i<graph[v].size();++i){
        singlePath.push_back(graph[v][i]);
        DFS(graph,graph[v][i]);
        //此处只能使用回溯
        singlePath.pop_back();
    }
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
{
    singlePath.push_back(0);
    DFS(graph,0);
    return result;
}