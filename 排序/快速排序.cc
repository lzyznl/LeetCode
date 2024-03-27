#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int singleSort(vector<int>& vt,int start,int end)
{
    int key = vt[start];
    while(start<end){
        while(vt[end]>=key&&end>start){
            --end;
        }
        vt[start]=vt[end];
        while(vt[start]<=key&&start<end){
            ++start;
        }
        vt[end]=vt[start];
    }
    vt[start]=key;
    return start;
}

void quickSort(vector<int>& vt,int start,int end){
    if(start>=end){
        return ;
    }
    int mid = singleSort(vt,start,end);
    quickSort(vt,start,mid-1);
    quickSort(vt,mid+1,end);
}

int main()
{
    vector<int> vt;
    int n;
    cin>>n;
    while(n--){
        int num;
        cin>>num;
        vt.push_back(num);
    }
    quickSort(vt,0,vt.size()-1);
    for(int i=0;i<vt.size();++i){
        cout<<vt[i]<<" ";
    }
    cout<<endl;
}