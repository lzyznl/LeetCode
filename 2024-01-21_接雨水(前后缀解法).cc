#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int trap(vector<int> &height)
{
    int length = height.size();
    vector<int> pre_max(length,0);
    vector<int> suf_max(length,0);
    pre_max[0]=height[0];
    suf_max[length-1]=height[length-1];
    //寻找前缀最大值
    for(int i=1;i<length;++i){
        pre_max[i]=max(pre_max[i-1],height[i]);
    }
    //寻找后缀最大值
    for(int j=length-2;j>=0;--j){
        suf_max[j]=max(suf_max[j+1],height[j]);
    }
    //计算结果:
    int ans = 0;
    for(int i=0;i<length-1;++i){
        ans += (min(pre_max[i],suf_max[i])-height[i]);
    }
    return ans;
}