#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//Floyd算法
int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    const int inf = INT32_MAX/2;
    vector<vector<int>> graph(n,vector<int>(n,inf));
    //初始化邻接矩阵
    for(auto& time:times){
        graph[time[0]-1][time[1]-1]=time[2];
    }
    for(int i=0;i<n;++i){
        graph[i][i]=0;
    }
    //本问题中无需路径矩阵，只需要不断更新邻接矩阵即可
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            for(int k=0;k<n;++k){
                if(graph[j][k]>graph[j][i]+graph[i][k]){
                    graph[j][k]=graph[j][i]+graph[i][k];
                }
            }
        }
    }
    int max = -1;
    for(int i=0;i<n;++i){
        if(graph[k-1][i]==inf){
            return -1;
        }else if(graph[k-1][i]>max){
            max=graph[k-1][i];
        }
    }
    return max;
}