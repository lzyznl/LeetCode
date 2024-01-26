#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    unordered_set<char> set;
    int length = s.length();
    int left=0;
    int right=0;
    int ans = 0;
    while(right<length){
        if(set.count(s[right])>0){
            ans = max(ans,static_cast<int>(set.size()));
            while(set.count(s[right])>0&&left<=right){
                set.erase(s[left]);
                left++;
            }
        }
        set.insert(s[right]);
        right++;
    }
    ans = max(ans,static_cast<int>(set.size()));
    return ans;
}

int main()
{
    string s="aab";
    int ans = lengthOfLongestSubstring(s);
    cout<<ans;
    return 0;
}
