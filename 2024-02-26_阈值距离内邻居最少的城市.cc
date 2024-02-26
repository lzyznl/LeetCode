#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
{
    const int inf = INT32_MAX / 2;
    vector<vector<int>> graph(n, vector<int>(n, inf));
    vector<vector<int>> result;
    for (auto &edge : edges)
    {
        graph[edge[0]][edge[1]] = edge[2];
        graph[edge[1]][edge[0]] = edge[2];
    }
    for (int i = 0; i < n; ++i)
    {
        vector<int> dist(n, inf);
        vector<int> isVisted(n, false);
        for (int j = 0; j < n; ++j)
        {
            dist[j] = graph[i][j];
        }
        dist[i] = 0;
        isVisted[i] = true;
        // 遍历剩余的n-1个顶点，计算单源最短路径即可
        for (int j = 0; j < n - 1; ++j)
        {
            int min = inf;
            int index = -1;
            for (int k = 0; k < n; ++k)
            {
                if (!isVisted[k] && dist[k] < min)
                {
                    min = dist[k];
                    index = k;
                }
            }
            if (index != -1)
            {
                isVisted[index] = true;
                for (int p = 0; p < n; ++p)
                {
                    if (!isVisted[p] && dist[p] > dist[index] + graph[index][p])
                    {
                        dist[p] = dist[index] + graph[index][p];
                    }
                }
            }
        }
        result.push_back(dist);
    }
    int min = inf;
    int index = -1;
    for (int i = 0; i < result.size(); ++i)
    {
        int count = 0;
        for (int j = 0; j < result[i].size(); ++j)
        {
            if (result[i][j] <= distanceThreshold)
            {
                count++;
            }
        }
        if (count <= min)
        {
            min = count;
            index = i;
        }
    }
    return index;
}