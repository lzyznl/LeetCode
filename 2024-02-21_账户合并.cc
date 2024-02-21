#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int find(vector<int>& s,int index){
    int root = index;
    while(s[root]>=0){
        root=s[root];
    }
    while(index!=root){
        int node = s[index];
        s[index]=root;
        index=node;
    }
    return root;
}

void unions(vector<int>& s,int index1,int index2){
    int root1 = find(s,index1);
    int root2 = find(s,index2);
    if(root1==root2){
        return;
    }
    if(root1<root2){
        s[root1]+=s[root2];
        s[root2]=root1;
    }else{
        s[root2]+=s[root1];
        s[root1]=root2;
    }
}

vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
{
    unordered_map<string,int> emailToIndex;
    unordered_map<string,string> emailToName;
    int index = 0;

    //将email和对应的并查集索引以及名字建立关系
    for(auto& account:accounts){
        string& name = account[0];
        int size = account.size();
        for(int i=1;i<size;++i){
            string& emailAccount = account[i];
            if(!emailToIndex.count(emailAccount)){
                emailToIndex[emailAccount]=index++;
                emailToName[emailAccount]=name;
            }
        }
    }

    //创建并查集
    vector<int> s(index,-1);

    //使用并查集对账户进行合并
    for(auto& account:accounts){
        string& email1 = account[1];
        int firstIndex = emailToIndex[email1];
        int size = account.size();
        for(int i=2;i<size;++i){
            string& email2 = account[i];
            int nextEamilIndex = emailToIndex[email2];
            unions(s,firstIndex,nextEamilIndex);
        }
    }

    unordered_map<int,vector<string>> rootIndexToEmail;
    for(auto& [email,_]:emailToIndex){
        int rootIndex = find(s,emailToIndex[email]);
        vector<string>& account = rootIndexToEmail[rootIndex];
        account.emplace_back(email);
        rootIndexToEmail[rootIndex]=account;
    }
    
    vector<vector<string>> result;
    for(auto& [_,email]:rootIndexToEmail){
        sort(email.begin(),email.end());
        string& name = emailToName[email[0]];
        vector<string> results;
        results.emplace_back(name);
        for(auto& emails:email){
            results.emplace_back(emails);
        }
        result.emplace_back(results);
    }
    return result;
}