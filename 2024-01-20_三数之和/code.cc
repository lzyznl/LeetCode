
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    // 先对数组进行整体的排序
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;
    int length = nums.size();


    for(int i=0;i<length-2;++i){
        if(i>0&&nums[i]==nums[i-1]){
            continue;
        }
        int right = length-1;
        for(int left=i+1;left<length;++left){
            if(left>i+1&&nums[left]==nums[left-1]){
                continue;
            }
            while(left<right){
                if(nums[i]+nums[left]+nums[right]==0){
                    ans.push_back({nums[i],nums[left],nums[right]});
                    break;
                }
                right--;
            }
        }
    }

    return ans;
}

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
    vector<vector<int>> fact = threeSum(nums);

    for(int i=0;i<fact.size();++i){
        cout<<fact[i][0]<<fact[i][1]<<fact[i][2]<<endl;
    }
}