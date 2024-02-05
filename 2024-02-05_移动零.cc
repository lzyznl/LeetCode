#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 快慢指针
*/
void moveZeroes(vector<int> &nums)
{
    int size = nums.size();
    int left=0,right=0;
    while(right<size){
        if(nums[right]){
            if(nums[left]==0){
                swap(nums[left],nums[right]);
            }
            left++;
        }
        right++;
    }
}