#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;
/**
 * author:lzy
 * 个人题解：https://leetcode.cn/problems/container-with-most-water/solutions/2617174/sheng-zui-duo-shui-de-rong-qi-by-elastic-bpzn/
*/
int maxArea(vector<int> &height)
{
    int length = height.size();
    int left = 0;
    int right = length-1;
    int ans = -1;
    while(left<right){
        ans = max(ans,(right-left)*min(height[right],height[left]));
        if(height[left]<=height[right]){
            left++;
        }else{
            right--;
        }
    }
    return ans;
}