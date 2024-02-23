#include <iostream>
#include <vector>
using namespace std;

int find(vector<int>& s,int x){
    int root = x;
    while(s[root]>=0){
        root=s[root];
    }
    while(x!=root){
        int t = s[x];
        s[x]=root;
        x=t;
    }
    return root;
}

bool unions(vector<int>& s,int index1,int index2){
    int root1 = find(s,index1);
    int root2 = find(s,index2);
    if(root1==root2){
        return false;
    }
    if(s[root1]<s[root2]){
        s[root1]+=s[root2];
        s[root2]=root1;
    }else{
        s[root2]+=s[root1];
        s[root1]=root2;
    }
    return true;
}


int maxNumEdgesToRemove(int n, vector<vector<int>> &edges)
{
    vector<int> s(n+1,-1);
    int ans = 0;
    //进行公共边处理
    for(auto& vt:edges){
        if(vt[0]==3){
            bool result = unions(s,vt[1],vt[2]);
            if(!result){
                ans++;
            }
        }
    }
    vector<int> ss = s;
    //处理独占边
    for(auto& vt:edges){
        if(vt[0]==1){
            bool result = unions(s,vt[1],vt[2]);
            if(!result) ans++;
        }else if(vt[0]==2){
            bool result = unions(ss,vt[1],vt[2]);
            if(!result) ans++;
        }
    }
    //判断一下连通分量数目
    int count1=0,count2=0;
    for(int i=1;i<n+1;++i){
        if(s[i]<=-1){
            count1++;
        }
        if(ss[i]<=-1){
            count2++;
        }
    }
    if((count1>1)||(count2>1)){
        return -1;
    }
    return ans;
}