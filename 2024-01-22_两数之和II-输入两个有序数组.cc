#include <iostream>
#include <vector>
using namespace std;

/**
 * author:lzy
 * 个人题解地址 https://leetcode.cn/problems/kLl5u1/solutions/2615378/liang-shu-zhi-he-ii-shu-ru-you-xu-shu-zu-xwe5/
*/
vector<int> twoSum(vector<int> &numbers, int target)
{
    vector<int> ans;
    int length = numbers.size();
    int left=0 ;
    int right = length-1;
    while(left<=right){
        int sum = numbers[left]+numbers[right];
        if(sum>target){
            right--;
        }else if(sum<target){
            left++;
        }else{
            ans.push_back(left);
            ans.push_back(right);
            break;
        }
    }
    return ans;
}