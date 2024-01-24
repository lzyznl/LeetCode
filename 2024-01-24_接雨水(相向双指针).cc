#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 之前使用前后缀解法，时间复杂度和空间复杂度均为O(N)
 * 时间复杂度我们已经无法继续优化了，但是空间复杂度我们还可以继续优化
 * 使用相向双指针动态更新前缀最大值以及后缀最大值，而不是用两个数组保存所有位置的当前前缀最大值以及后缀最大值
 * 这样我们就实现了空间复杂度为O(1)
 * 具体代码如下所示
 * 
 * author:lzy
 * 个人题解:https://leetcode.cn/problems/trapping-rain-water/solutions/2618643/jie-yu-shui-by-elastic-hypatiadmy-2ij2
*/

int trap(vector<int> &height)
{
    int length = height.size();
    int left=0;
    int right=length-1;
    int pre_max = height[0];
    int suf_max = height[length-1];
    int ans = 0;
    while(left<=right){
        //更新前缀最大值以及后缀最大值
        pre_max = max(pre_max,height[left]);
        suf_max = max(suf_max,height[right]);
        if(pre_max<=suf_max){
            ans += pre_max-height[left];
            left++;
        }else{
            ans += suf_max-height[right];
            right--;
        }
    }
    return ans;
}