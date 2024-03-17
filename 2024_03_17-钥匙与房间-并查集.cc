#include <iostream>
#include <vector>

using namespace std;

int find(vector<int> &vt, int v)
{
    while(vt[v]!=v){
        v=vt[v];
    }
    return v;
}

void unions(vector<int> &vt, int v1, int v2,int& count)
{
    int v1_root = find(vt, v1);
    int v2_root = find(vt, v2);
    if(v1_root!=v2_root){
        vt[v2_root]=v1_root;
        vt[v1_root]++;
        //联通分量数-1
        count--;
    }
}

bool canVisitAllRooms(vector<vector<int>> &rooms)
{
    int n = rooms.size();
    vector<int> vt(n);
    for(int i=0;i<n;++i){
        vt[i]=i;
    }
    int count = n;
    for (int i = 0; i < rooms.size(); ++i)
    {
        for(int key:rooms[i]){
            unions(vt, i,key,count);
        }
    }
    for(int i=1;i<n;++i){
        if(vt[i]==i){
            return false;
        }
    }
    return true;
}