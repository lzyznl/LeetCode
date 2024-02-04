#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <set>
using namespace std;

/**
 * 思想：
 * 先对数组进行排序
 * 然后对排序后的数组进行去重
 * 去重完成之后遍历set，不断更新最长连续序列
 * 时间复杂度应该是O(NlogN)的
*/
int longestConsecutive1(vector<int> &nums)
{
    if(nums.size()==0){
        return 0;
    }
    sort(nums.begin(),nums.end());
    set<int> myset;
    for(int i=0;i<nums.size();++i){
        myset.insert(nums[i]);
    }
    int ans = -1;
    int pre = *myset.begin();
    int temp = 1;
    for(int num:myset){
        if(num-pre==1){
            temp+=1;
        }else{
            ans = max(ans,temp);
            temp=1;
        }
        pre=num;
    }
    ans = max(ans,temp);
    return ans;
}

/**
 * 时间复杂度：O(N)
*/
int longestConsecutive(vector<int> &nums)
{
    unordered_set<int> myset;
    for(int i=0;i<nums.size();++i){
        myset.insert(nums[i]);
    }
    int currentLength=0;
    int maxLength=0;
    for(int num:myset){
        currentLength=0;
        if(myset.count(num-1)==0){
            currentLength++;
            while(myset.count(++num)!=0){
                currentLength++;
            }
            maxLength=max(maxLength,currentLength);
        }else{
            continue;
        }
    }
    return maxLength;
}

int main()
{
    int n;
    cin>>n;
    vector<int> vt;
    while(n--){
        int num;
        cin>>num;
        vt.push_back(num);
    }
    longestConsecutive(vt);
}