#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * author:lzy
 * 个人题解 https://leetcode.cn/problems/3sum/solutions/2615443/san-shu-zhi-he-ti-jie-by-elastic-hypatia-n5h1/
*/
vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;
    //先对数组进行排序
    sort(nums.begin(),nums.end());
    int length = nums.size();
    //枚举所有的值
    for(int i=0;i<=length-3;++i){
        //如果这次和上一次一样可以直接跳过
        if(i>0&&nums[i]==nums[i-1]){
            continue;
        }
        //如果排序之后最小的三个数相加大于0，那么之后全部都大于0，没有符合条件的数据
        if((nums[i]+nums[i+1]+nums[i+2])>0){
            break;
        }
        //如果最小的一个数，加上最大的两个数都小于0，那么可以直接跳过这个数的循环
        if((nums[i]+nums[length-2]+nums[length-1])<0){
            continue;
        }
        int left=i+1;
        int right=length-1;
        while (left<right)
        {
            int sum = nums[i]+nums[left]+nums[right];
            if(sum>0){
                right--;
            }
            else if(sum<0){
                left++;
            }else{
                ans.push_back({nums[i],nums[left],nums[right]});
                //去除重复元素
                left++;
                while(left<right&&nums[left]==nums[left-1]){
                    left++;
                }
                right--;
                while(right>left&&nums[right]==nums[right+1]){
                    right--;
                }
            }
        }  
    }
    return ans;
}

//测试程序代码
int main()
{
    vector<int> nums;
    int n;
    cin>>n;
    while(n--){
        int num;
        cin>>num;
        nums.push_back(num);
    }
    vector<vector<int>> result = threeSum(nums);
    for(int i=0;i<result.size();++i){
        cout<<result[i][0]<<" "<<result[i][1]<<" "<<result[i][2]<<endl;
    }
}