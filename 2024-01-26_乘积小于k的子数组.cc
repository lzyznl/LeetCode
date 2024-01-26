#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int numSubarrayProductLessThanK(vector<int> &nums, int k)
{
    int size = nums.size();
    int left=0;
    int right=0;
    int ans =  0;
    int result = 1;
    while (right<size)
    {
        result*=nums[right];
        if(result<k){
            ans+=(right-left+1);
        }else{
            while(left<=right&&result>=k){
                result/=nums[left];
                left++;
            }
            ans+=(right-left+1);
        }
        right++;
    }
    return ans;
}