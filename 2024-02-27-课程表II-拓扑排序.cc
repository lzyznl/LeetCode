#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    const int inf = INT32_MAX / 2;
    vector<int> result;
    vector<vector<int>> edge;
    edge.resize(numCourses);
    vector<int> inedge(numCourses, 0);
    for (auto &info : prerequisites)
    {
        edge[info[1]].push_back(info[0]);
        ++inedge[info[0]];
    }
    queue<int> queue;
    for (int i = 0; i < inedge.size(); ++i)
    {
        if (!inedge[i])
        {
            queue.push(i);
        }
    };
    int visited = 0;
    while (!queue.empty())
    {
        ++visited;
        int node = queue.front();
        result.push_back(node);
        queue.pop();
        for (int v : edge[node])
        {
            --inedge[v];
            if (inedge[v] == 0)
            {
                queue.push(v);
            }
        }
    }
    if (visited != numCourses)
    {
        result.clear();
    }
    return result;
}