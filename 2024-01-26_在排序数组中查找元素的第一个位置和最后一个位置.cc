#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int quickFind(vector<int> nums,int target){
    int left=0;
    int right = nums.size()-1;
    while(left<=right){
        int mid = left+(right-left)/2;
        if(nums[mid]<target){
            left=mid+1;
        }else{
            right=mid-1;
        }
    }
    return left;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    int start = quickFind(nums,target);
    int end = quickFind(nums,target+1)-1;
    if(start<=end&&end<nums.size()&&nums[start]==target&&nums[end]==target){
        return vector<int>{start,end};
    }
    return vector<int>{-1,-1};
}