#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string,vector<string>> hashMap;
    vector<vector<string>> vt;
    for(int i=0;i<strs.size();++i){
        string prestr = strs[i];
        sort(strs[i].begin(),strs[i].end());
        auto it = hashMap.find(strs[i]);
        if(it!=hashMap.end()){
            hashMap[strs[i]].push_back(prestr);
        }else{
            vector<string> strVt;
            strVt.push_back(prestr);
            hashMap.insert(make_pair(strs[i],strVt));
        }
    }

    for(unordered_map<string,vector<string>>::iterator it=hashMap.begin();it!=hashMap.end();it++){
        vt.push_back(it->second);
    }
    return vt;
}