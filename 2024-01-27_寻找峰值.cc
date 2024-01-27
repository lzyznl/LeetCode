#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findPeakElement(vector<int> &nums)
{
    int size = nums.size();
    int left=0;
    int right = size-1;
    while(left<right){
        int mid = left+(right-left)/2;
        if(nums[mid]<nums[mid+1]){
            left=mid+1;
        }else{
            right=mid;
        }
    }
    return left;
}