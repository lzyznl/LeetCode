#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/**
 * 反悔贪心
 * 个人题解:https://leetcode.cn/problems/p0NxJO/solutions/2634203/mo-ta-you-xi-by-elastic-hypatiadmy-fhk3/
*/
int magicTower(vector<int> &nums)
{
    priority_queue<int> que;
    int ans=0;
    long long initFlood=1;
    for(int num:nums){
        initFlood+=num;
    }
    if(initFlood<=0){
        return -1;
    }
    initFlood=1;
    for(int num:nums){
        if(num<0){
            que.push(-num);
        }
        initFlood+=num;
        if(initFlood<1){
            //返回贪心
            ans++;
            initFlood+=que.top();
            que.pop();
        }
    }
    return ans;
}