#include <iostream>
#include <vector>
using namespace std;

//迪姐斯塔拉算法实现
int networkDelayTime_dj(vector<vector<int>> &times, int n, int k)
{
    const int inf = INT32_MAX/2;
    vector<vector<int>> edge(n,vector<int>(n,inf));
    //构建邻接矩阵
    for(int i=0;i<times.size();++i){
        edge[times[i][0]-1][times[i][1]-1]=times[i][2];
    }
    vector<int> dist(n,inf);
    vector<bool> isVisited(n,false);
    //初始化dist数组
    for(int i=0;i<n;++i){
        if(edge[k-1][i]!=inf){
            dist[i]=edge[k-1][i];
        }
    }
    dist[k-1]=0;
    isVisited[k-1]=true;
    //开始最短路径求解
    for(int i=0;i<n-1;++i){
        //先找到当前dist数组中还未遍历到的最小值
        int min = inf;
        int index = -1;
        for(int i=0;i<n;++i){
            if(!isVisited[i]&&dist[i]<min){
                min = dist[i];
                index = i;
            }
        }
        if(index==-1){
            //没有找到最小值
            return index;
        }
        isVisited[index]=true;
        //找到当前最小值，则开始进行距离更新
        for(int i=0;i<n;++i){
            if(!isVisited[i]&&edge[index][i]+dist[index]<dist[i]){
                dist[i]=edge[index][i]+dist[index];
            }
        }
    }
    int ans = -1;
    for(int i=0;i<n;++i){
        if(dist[i]>ans){
            ans=dist[i];
        }
    }
    return ans;
}

//使用弗洛伊德算法实现
int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    const int inf = INT32_MAX/2;
    vector<vector<int>> edge(n,vector<int>(n,inf));
    for(int i=0;i<times.size();++i){
        edge[times[i][0]-1][times[i][1]-1]=times[i][2];
    }
    for(int i=0;i<n;++i){
        edge[i][i]=0;
    }
    //开始进行迭代
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            for(int k=0;k<n;++k){
                if(edge[j][k]>edge[j][i]+edge[i][k]){
                    edge[j][k]=edge[j][i]+edge[i][k];
                }
            }
        }
    }
    int ans = -1;
    for(int i=0;i<n;++i){
        if(edge[k-1][i]==inf){
            return -1;
        }
        else if(edge[k-1][i]>ans){
            ans=edge[k-1][i];
        }
    }
    return ans;
}