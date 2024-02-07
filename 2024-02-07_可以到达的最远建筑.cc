#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int furthestBuilding(vector<int> &heights, int bricks, int ladders)
{
    priority_queue<int,vector<int>,greater<int>> que;
    int size = heights.size();
    int ans = 0;
    int sum = 0;
    for(int i=0;i<size-1;++i){
        int num = heights[i+1]-heights[i];
        if(num>0){
            que.push(num);
            if(que.size()>ladders){
                sum+=que.top();
                que.pop();
            }
            if(sum>bricks){
                return i;
            }
        }
    }
    return size-1;
}