#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * 两数之和，使用hash表
*/
vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int,int> hashTable;
    for(int i=0;i<nums.size();++i){
        auto it = hashTable.find(target-nums[i]);
        if(it!=hashTable.end()){
            return {it->second,i};
        }
        hashTable.insert({nums[i],i});
    }
    return {};
}